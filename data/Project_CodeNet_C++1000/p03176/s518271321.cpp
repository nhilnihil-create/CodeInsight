#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI acos(-1)
#define vi vector<int>
#define pi pair<int, int>
#define pl pair<ll, ll>
template<class T> istream &operator>>(istream&is,vector<T>&v){for(auto &elemnt:v)is>>elemnt;return is;}
template<class T,class U> istream &operator>>(istream&is,pair<T,U>&p){is>>p.first>>p.second;return is;}
const int MOD = 1e9+ 7;
const int INF = numeric_limits<int>::max() - (int)1e8;
const ll INFLL = numeric_limits<ll>::max() - (ll)1e17;

template<typename M>
class SegmentTree {
private:
    vector<M> data;
    const function<M(M, M)> merge;
    const M identity_element;
    size_t base_data_size;

    void data_size_calc_and_init(size_t N) {
        base_data_size = 1;
        while (base_data_size < N) base_data_size <<= 1;
        data = vector<M>(2 * base_data_size, identity_element);
    }

    void build() {
        for (size_t index = base_data_size - 1; index > 0; index--) {
            data[index] = merge(data[2 * index], data[2 * index + 1]);
        }
    }

public:
    explicit SegmentTree(size_t N, const function<M(M, M)> merge, const M identity_element) : merge(merge), identity_element(identity_element) {
        data_size_calc_and_init(N);
    }

    explicit SegmentTree(const vector<M> &init_data, const function<M(M, M)> merge, const M identity_element) : merge(merge), identity_element(identity_element) {
        data_size_calc_and_init(init_data.size());
        for (size_t index = 0; index < init_data.size(); index++) {
            data[base_data_size + index] = init_data[index];
        }
        build();
    }

    void update(size_t index, M value) {
        index += base_data_size;
        data[index] = value;
        while (index >>= 1) {
            data[index] = merge(data[2 * index], data[2 * index + 1]);
        }
    }

    // [left, right)
    M query(size_t left_index, size_t right_index) {
        M left = identity_element, right = identity_element;
        left_index += base_data_size;
        right_index += base_data_size;
        while (left_index < right_index) {
            if (left_index & 1) left = merge(left, data[left_index++]);
            if (right_index & 1) right = merge(data[--right_index], right);
            left_index >>= 1;
            right_index >>= 1;
        }
        return merge(left, right);
    }

    const M &operator[](const size_t index) {
        return data[index + base_data_size];
    }
};

int main() {
    int N;
    cin >> N;
    vector<pair<int, ll>> input(N);
    for (int i = 0; i < N; i++) cin >> input[i].first;
    for (int i = 0; i < N; i++) cin >> input[i].second;
    auto merge = [](ll a, ll b) {
        return max(a, b);
    };
    SegmentTree<ll> tree(N + 1, merge, 0);
    vector<ll> dp(N, 0);
    for (int i = 0; i < N; i++) {
        ll before = tree.query(0, input[i].first);
        dp[i] = before + input[i].second;
        tree.update(input[i].first, dp[i]);
    }
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
}

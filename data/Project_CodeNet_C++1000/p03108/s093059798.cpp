#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI arccos(-1)
#define rep(i, N) for (int i = 0; i < (N); i++)
#define REP(i, a, N) for (int i = a; i < (N); i++)
#define rrep(i, N, k) for (int i = (N); i >= (k); i--);
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pi pair<int, int>
#define pl pair<ll, ll>
template<class T> istream &operator>>(istream&is,vector<T>&v){for(auto &elemnt:v)is>>elemnt;return is;}
template<class T,class U> istream &operator>>(istream&is,pair<T,U>&p){is>>p.first>>p.second;return is;}
const int MOD = 1e9+ 7;
const int INF = numeric_limits<int>::max() - (int)1e8;
const ll INFLL = numeric_limits<ll>::max() - (ll)1e17;

struct UnionFind {
    vector<int> data;

    explicit UnionFind(int size) : data(size, -1)  {}

    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return false;
        if(data[x] > data[y]) swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return true;
    }

    int find(int idx) {
        if (data[idx] < 0) return idx;
        else return (data[idx] = find(data[idx]));
    }

    int size(int idx) {
        return (-data[find(idx)]);
    }
};

int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> A(M), B(M);
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i];
        A[i]--; B[i]--;
    }

    auto data = UnionFind(N);

    ll temp = 0;
    vector<ll> ans(M, 0);
    for (int i = M - 1; i >= 0; i--) {
        ans[i] = N * (N - 1) / 2 - temp;
        if (data.find(A[i]) != data.find(B[i])) {
            temp += data.size(A[i]) * data.size(B[i]);
            data.unite(A[i], B[i]);
        }
    }
    for (auto now : ans) cout << now << endl;
}

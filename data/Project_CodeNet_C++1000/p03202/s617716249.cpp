#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PI 3.141592653589793
#define rep(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, n) for (int i = a; i < (n); i++)
#define rrep(i, n, k) for (int i = (n); i >= (k); i--);
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
template<class T> istream &operator>>(istream&is,vector<T>&v){for(auto &elemnt:v)is>>elemnt;return is;}
template<class T,class U> istream &operator>>(istream&is,pair<T,U>&p){is>>p.first>>p.second;return is;}
template<class T>vector<T> make_vector(size_t a){return vector<T>(a);}
template<class T, class... Ts>auto make_vector(size_t a, Ts... ts){return vector<decltype(make_vector<T>(ts...))>(a, make_vector<T>(ts...));}
const int MOD = 1e9+ 7;
const int INF = 2e18;

signed main() {
    int N;
    cin >> N;
    vector<int> A(N);
    cin >> A;
    auto check = [&](int types) {
        map<int, int> count;
        for (int i = 1; i < N; i++) {
            if (A[i - 1] < A[i]) continue;
            int idx = A[i];
            if (types == 1) return false;
            while (true) {
                count[idx]++;
                if (count[idx] >= types) {
                    count.erase(idx);
                    idx--;
                } else break;
            }
            auto itr = next(count.find(idx), 1);
            while (itr != count.end()) itr = count.erase(itr);
        }
        bool ok = count[0] == 0;
        return ok;
    };
    int left = 0, right = 1e9 + 100;
    while (right - left > 1) {
        int mid = left + (right - left) / 2;
        if (check(mid)) right = mid;
        else left = mid;
    }
    cout << right << endl;
}

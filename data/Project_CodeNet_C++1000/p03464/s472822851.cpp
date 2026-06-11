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
const int MOD = 1e9 + 7;
const int INF = 2e18;

signed main() {
    int K;
    cin >> K;
    vector<int> A(K);
    cin >> A;
    if (A[K - 1] != 2) {
        cout << -1 << endl;
        return 0;
    }
    int minValue = 2, maxValue = 3;
    for (int i = K - 2; i >= 0; i--) {
        int now = (minValue / A[i] + (minValue % A[i] != 0)) * A[i];
        if (minValue <= now && now <= maxValue) {
            minValue = now;
            maxValue = (maxValue / A[i]) * A[i] + A[i] - 1;
        } else {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << minValue << " " << maxValue << endl;
}

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
    int N;
    cin >> N;
    vector<int> a(N), b(N);
    cin >> a >> b;
    int dif = 0;
    for (int i = 0; i < N; i++) {
        if (a[i] < b[i]) {
            dif += (b[i] - a[i]) / 2;
        } else {
            dif -= (a[i] - b[i]);
        }
    }
    cout << (dif >= 0 ? "Yes" : "No") << endl;
}

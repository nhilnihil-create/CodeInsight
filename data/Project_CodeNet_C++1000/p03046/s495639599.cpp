#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PI 3.141592653589793
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n, k) for (int i = (n); i >= (k); i--);
#define all(x) (x).begin(), (x).end()
template<class T> istream &operator>>(istream&is,vector<T>&v){for(auto &elemnt:v)is>>elemnt;return is;}
template<class T,class U> istream &operator>>(istream&is,pair<T,U>&p){is>>p.first>>p.second;return is;}
template<class T>vector<T> make_vector(size_t a){return vector<T>(a);}
template<class T, class... Ts>auto make_vector(size_t a, Ts... ts){return vector<decltype(make_vector<T>(ts...))>(a, make_vector<T>(ts...));}
const int inf = 2e17;
const int mod = 1e9 + 7;

signed main() {
    int M, K;
    cin >> M >> K;
    if (M == 0 && K == 0) {
        cout << "0 0" << endl;
    } else if (M == 1 && K == 0) {
        cout << "0 0 1 1" << endl;
    } else if (M >= 2 && K < (1<<M)) {
        for (int i = 0; i < (1<<M); i++) {
            if (i == K) continue;
            cout << i << " ";
        }
        cout << K << " ";
        for (int i = (1<<M) - 1; i>= 0; i--) {
            if (i == K) continue;
            cout << i << " ";
        }
        cout << K << endl;
    } else {
        cout << -1 << endl;
    }
}

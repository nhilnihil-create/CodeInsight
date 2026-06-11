#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
template<typename T> void view(T cont) {std::cout << cont << std::endl;}
template<typename T> void view(T* cont, ll sz) {rep(i, sz) std::cout << cont[i] << " "; std::cout << std::endl;}
template<typename T> void view(const std::vector<T>& v) {for (const auto& f: v) std::cout << f << " "; std::cout << std::endl;}
template<typename T> void view(const std::vector<std::vector<T> >& vv) { for (const auto& v: vv) {view(v);}}
const long long INF = 1LL<<60;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main(){
    int D; cin >> D;
    if (D == 25) {
        cout << "Christmas" << endl;
    } else if (D == 24) {
        cout << "Christmas Eve" << endl;
    } else if (D == 23) {
        cout << "Christmas Eve Eve" << endl;
    } else if (D == 22) {
        cout << "Christmas Eve Eve Eve" << endl;
    }
}
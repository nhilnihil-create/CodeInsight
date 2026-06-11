#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<long,long>;
using veci = vector<int>;
using vecl = vector<long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;

int main() {
    ll N;
    cin >> N;
    for(ll n = 1; n <= 3500; n++) {
        for(ll h = 1; h <= 3500; h++) {
            ll p = N*h*n;
            ll q = 4*n*h-N*n-N*h;
            if(p*q > 0 && p%q == 0) {
                cout << n << " "<< h << " " << p/q << endl;
                return 0;
            }
        }
    }
}


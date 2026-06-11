#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
int main(){
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    ll pow_m2 = 1;
    string s = "";
    if(n == 0) s = "0";
    while(n!=0) {
        if(n%(pow_m2*(-2)) != 0) {
            n -= pow_m2;
            s = to_string(1)+s;
        } else {
            s = to_string(0)+s;
        }
        pow_m2*=-2;
    }
    cout << s << endl;
}

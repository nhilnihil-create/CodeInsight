#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int minus = 0;
    bool zero = false;
    ll sum = 0, miabs = 1e18;
    rep(i,n){
        ll a;
        cin >> a;
        if(a > 0){
            chmin(miabs, a);
            sum += a;
        }
        else if(a == 0) zero = true;
        else{
            ++minus;
            if(-a < miabs) chmin(miabs, -a);
            sum -= a;
        }
    }
    if(zero || minus%2 == 0) cout << sum << endl;
    else cout << sum - miabs * 2 << endl;
    return 0;
}

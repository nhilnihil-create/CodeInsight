#include<bits/stdc++.h>
#define ll long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));
const int MOD = 1000000007;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")




int main() {


    ll n; cin >> n;
    string s;
    ll a = 0, b = 0, c = 0, ans = 0;
    rep(i,n){
        cin >> s;
        if(s[0] == 'B' && s[s.length()-1] == 'A') c ++;
        else if(s[s.length()-1] == 'A') a ++;
        else if(s[0] == 'B') b ++;
        rep(j,s.length()-1){
            if(s[j] == 'A' && s[j+1] == 'B') ans ++;
        }

    }
    
    if(c == 0) cout << ans + min(a,b);
    else{
        if(a+b == 0) cout << ans + c-1;
        else cout << ans + c + min(a,b);
    }



    return 0;
}

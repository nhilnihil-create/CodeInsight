#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    string s;
    cin >> s;
    int n = s.length();
    ll a_cnt = 0;
    ll ans = 0;
    rep(i, n) {
        if ( s[i] == 'A' ) {
            ++a_cnt;
        }
        else if ( i < n - 1 && s[i] == 'B' && s[i+1] == 'C' ) {
            ans += a_cnt;
            ++i;
        }
        else {
            a_cnt = 0LL;
        }
    }
    cout << ans << endl;
    return 0;
}

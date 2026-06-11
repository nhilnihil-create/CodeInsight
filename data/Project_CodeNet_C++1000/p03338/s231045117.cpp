#include<bits/stdc++.h>
// #define int long long
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
#define MOD 1000000007
using namespace std;
using ll = long long;
typedef vector<int> vi;

signed main() {
    
    int ans = 0;
    int n;
    cin >> n;
    string s;
    cin >> s;
    repa(i, 1, n){
        int tmp = 0;
        /* a = 0, z = 25 */
        vector<bool> x(26, false), y(26, false);
        rep(j, i){
            x[s[j]-'a'] = true;
        }
        repa(k, i, n){
            y[s[k]-'a'] = true;
        }
        rep(l, 26){
            if(x[l] && y[l]){
                tmp++;
                // cout << l << " ";
            }
        }
        ans = max(ans, tmp);
        // cout << tmp << endl;
        // rep(t, 26) cout << x[t] << " " << y[t] << "   ";
        // cout << endl;
    }
    cout << ans << endl;
    return 0;
}
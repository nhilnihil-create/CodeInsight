#include <bits/stdc++.h>
using namespace std;

//#define int long long
struct Fast {Fast(){cin.tie(0);ios::sync_with_stdio(0);}} fast;
using intpair = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()

signed main() {
    string s;
    cin >> s;
    int l = 0, r = (int)s.length()-1;
    int ans = 0;
    while(l < r){
        if(s[l] != s[r]){
            if(s[l] == 'x'){
                r++;
            }else if(s[r] == 'x'){
                l--;
            }else{
                ans = -1; break;
            }
            ans++;
        }
        l++; r--;
    }
    cout << ans << endl;
}
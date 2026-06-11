#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    string s;
    cin >> s;
    ll n = s.size();
    ll ans = 0;
    rep(i, 0, n){
        rep(j, 0, n) {
            if(i > j) continue;
            bool f = true;
            rep(k, i, j+1) {
                if(s[k] != 'A' && s[k] != 'G' && s[k] != 'C' && s[k] != 'T') f = false;
            }
            if(f) ans = max(ans, j - i + 1);
        }
    }
    cout << ans << endl;
    return 0;
}
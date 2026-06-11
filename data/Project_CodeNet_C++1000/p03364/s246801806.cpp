 #include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){

    // input
    ll n;
    cin >> n;
    vector<string> s(n);
    rep(i, 0, n) cin >> s[i];

    // full-search
    ll ans = 0;
    vector<string> t(n, string(n, '0'));
    rep(a, 0, n) {
        rep(i, 0, n) {
            rep(j, 0, n) {
                ll ni = (i + a) % n;
                t[ni][j] = s[i][j];
            }
        }
        bool f = true;
        rep(i, 0, n) {
            rep(j, 0, n) {
                if(t[i][j] != t[j][i]) f = false; 
            }
        }
        if(f) ans += n;
    }

    // output
    cout << ans << endl;
    return 0;
}
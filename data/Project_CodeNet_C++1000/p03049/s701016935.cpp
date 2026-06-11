#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
typedef vector<ll> vel;
typedef vector<str> ves;
#define REP(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define rep(i, b) REP(i, 0, b)
const ll mod = 1000000007;
const double pi = 3.14159265358979;

int main() {
    ll n;
    cin >> n;ll cnt = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0;
    ves s(n);
    rep(i, n) {
        cin >> s[i];
        rep(j, s[i].size() - 1) {
            if(s[i][j] == 'A' && s[i][j+1] == 'B') {
                cnt++;
            }
        }
    }
    rep(i, n){
        if(s[i][0] == 'B' && s[i][s[i].size()-1] == 'A') {
            cnt1++;
        }
        if(s[i][0] == 'B' && s[i][s[i].size()-1] != 'A') {
            cnt2++;
        }
        if(s[i][0] != 'B' && s[i][s[i].size()-1] == 'A') {
            cnt3++;
        }
    }
    if(cnt1 == 0){
        cout << cnt + min(cnt2, cnt3) << endl;
    }
    else {
        if(cnt2 + cnt3 != 0){
            cout << cnt + cnt1 + min(cnt2, cnt3) << endl;
        }
        else {
            cout << cnt + cnt1 - 1 << endl;
        }
    }
}
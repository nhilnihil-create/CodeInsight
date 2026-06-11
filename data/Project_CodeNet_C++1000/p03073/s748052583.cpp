#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define ve vector

int main(){
    string s;
    cin >> s;
    int ans=0,memo=0;
    int now = 0;
    int n = s.size();
    rep(i,n){
        if(s[i]-'0' != now) ans++;
        now = 1-now;
    }
    now = 1;
    rep(i,n){
        if(s[i]-'0' != now) memo++;
        now = 1-now;
    }
    ans = min(ans,memo);
    cout << ans << endl;
    return 0;
}
#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int ans = 0;

void dfs(string s, ll n){
    if(atoll(s.c_str())>n)return;
    vector<bool> m(3, false);
    rep(i, s.size()){
        if(s[i] == '3') m[0] = true;
        if(s[i] == '5') m[1] = true;        
        if(s[i] == '7') m[2] = true;
        if(m[0]&&m[1]&&m[2]){
            ans++;
            break;
        }
    }
    dfs(s+'3', n);
    dfs(s+'5', n);
    dfs(s+'7', n);
    return;
}

int main(){
    ll n;
    cin >> n;
    dfs("0", n);
    cout << ans << endl;
}
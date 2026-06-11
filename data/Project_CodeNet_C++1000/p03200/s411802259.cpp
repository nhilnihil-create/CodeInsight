#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    string s;
    cin >> s;
    vector<ll>wh;
    for(ll i=0;i<s.size();i++){
        if(s[i]=='W'){
            wh.push_back(i);
        }
    }
    ll ans=0,ju=0;
    for(ll i=0;i<wh.size();i++){
        ans+=wh[i]-ju;
        ju++;
    }
    cout << ans << endl;
}
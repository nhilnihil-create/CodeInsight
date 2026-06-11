#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    string s,t;
    cin >> s >> t;
    ll n=t.size();
    ll x=s.size();
    if(x<n){
        cout << "UNRESTORABLE" << endl;
        return 0;
    }
    ll check=MOD;
    for(ll i=x-n;i>=0;i--){
        bool judge=true;
        for(ll j=0;j<n;j++){
            if(s[i+j]!='?'&&s[i+j]!=t[j]){
                judge=false;
            }
        }
        if(judge){
            check=i;
            break;
        }
    }
    if(check==MOD){
        cout << "UNRESTORABLE" << endl;
        return 0;
    }
    string ans=s;
    for(ll i=0;i<x;i++){
        if(check==i){
            for(ll j=0;j<n;j++){
                ans[i+j]=(t[j]);
            }
            i+=n;
        }

        if(ans[i]=='?'){
            ans[i]='a';
        }
    }
    cout << ans << endl;
}
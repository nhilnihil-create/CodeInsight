#include "bits/stdc++.h"
#define rep(i,b) for(ll i=0;i<b;i++)
#define ll long long
using namespace std;
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vvvl vector<vector<vector<ll>>>
#define debug(x) cerr<<#x<<" "<<x<<'\n';

ll gcd(ll a,ll b) {
    while(1) {
        if(a < b) swap(a, b);
        if(!b) break;
        a %= b;
    }
    return a;
}
int main() {
    string s;
    ll ans=0,cnt=0;
    cin>>s;
    rep(i,s.length()){
        if(s[i]=='A')cnt++;
        else if(s[i]=='B'&&s[i+1]=='C'){
            ans+=cnt;
            i++;
        }
        else cnt=0;
    }
    cout<<ans<<endl;
}


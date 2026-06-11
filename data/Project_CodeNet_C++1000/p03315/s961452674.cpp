#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using Map = map<ll,ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
ll INF=1LL<<60;
ll MOD=1000000007;



int main(){
    string s;
    cin >> s;ll ans=0;
    for(ll i=0;i<4;i++){
        if(s[i]=='+')ans++;
        else ans--
    ;}cout<<ans<<endl;
    
    return 0;
}

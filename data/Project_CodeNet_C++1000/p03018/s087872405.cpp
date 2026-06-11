#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using Map = map<string,ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
ll INF=1LL<<60;
ll MOD=1000000007;

int main(){
    string S;
    cin >> S;
    ll a=0;
    while(a<S.size()-1){
        if(S[a]=='B'&&S[a+1]=='C'){
            S=S.substr(0,a)+'D'+S.substr(a+2);
        }a++;
    }
    ll ans=0;
    ll acounter=0;
    for(ll i=0;i<S.size();i++){
        if(S[i]=='A')acounter++;
        else if(S[i]=='D')ans+=acounter;
        else acounter=0;
    ;}
    cout<<ans<<endl;
    return 0;
}

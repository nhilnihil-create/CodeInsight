#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using Map = map<ll,ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
const ll INF=1LL<<60;
const ll MOD=1000000007;




int main(){
    ll N;
    cin >> N;

    vector<ll> ans(0);

    //右からM桁目を確定させる
    ll M=0LL;
    while(N!=0LL||M==65LL){
        if(llabs(N)%(1LL<<(M+1))!=0LL){
            ans.emplace_back(1);
            N-=pow(-2LL,M);
        }
        else ans.emplace_back(0);
        M++;
    }
    if(ans.empty()){
        cout<<0<<endl;return 0;
    }
    ll j=ans.size();
    for(ll i=j-1;i>=0;i--){
        cout<<ans[i]
    ;}cout<<endl;
    

    return 0;
}

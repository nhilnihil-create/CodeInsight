#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
const ll M=1000000007;
//------------------------------------------//

int main(){
    ll N,K;cin>>N>>K;
    vector<ll> x(101000,0);
    rep(i,N){
        cin>>x[i];
    }
    ll y=M;
    rep(i,N-K+1){
        ll a=min(abs(x[i]),abs(x[i+K-1]))+abs(x[i+K-1]-x[i]);
        y=min(a,y);
    }
    cout<<y<<endl;        
}
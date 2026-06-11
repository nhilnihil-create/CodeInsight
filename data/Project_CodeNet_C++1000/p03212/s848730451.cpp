#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define sz(x) int(x.size())
#define pb push_back
#define eb emplace_back
using ll=long long;
using P = pair<int,int>;
using LP=pair<ll,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
const ll MOD=1000000007,MOD2=998244353;

ll power(ll n,ll p){
    if(p==0){return 1;}
    if(p%2==1){return n*power(n,(p-1)/2)*power(n,(p-1)/2);}
    else{return power(n,p/2)*power(n,p/2);}
}

int main() {
    ll N;
    cin>>N;
    if(N<357){cout<<0<<endl;return 0;}
    ll ans=0;
    ll X=N;int keta=0;
    while(X>0){keta++;X/=10;}
    for(int i=3;i<=keta;i++){
        for(ll S=0;S<power(3,i);S++){
            ll Y=0;
            ll SC=S;
            vector<bool> a(3,false);
            rep(j,i){
                Y*=10;
                int p=SC%3;
                a.at(p)=true;
                Y+=p*2+3;
                SC/=3;
            }
            if(a.at(0) && a.at(1) && a.at(2))if(Y<=N)ans++;
        }
    }
    cout<<ans<<endl;
}
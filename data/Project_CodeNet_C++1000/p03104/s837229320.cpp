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



int main() {
    ll A,B;
    cin>>A>>B;
    if(B-A<=10){
        ll ans=A;
        for(ll i=A+1;i<=B;i++){
            ans=ans^i;
        }
        cout<<ans<<endl;
        return 0;
    }
    ll ansa,ansb,ans;
    ansa=A,ansb=B;
    ll nowa=A+1,nowb=B-1;
    while(nowa%4!=0){
        ansa=ansa^nowa;
        nowa++;
    }
    while(nowb%4!=3){
        ansb=ansb^nowb;
        nowb--;
    }

    ans=ansa^ansb;
    cout<<ans<<endl;
}
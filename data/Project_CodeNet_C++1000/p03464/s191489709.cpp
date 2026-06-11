#include<bits/stdc++.h>
#include<unistd.h>
#define REP(i,n) for(int i=0,i##_len=(n);i<i##_len;++i)
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define All(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;

int main(){
    ll K;cin>>K;
    vector<ll> A(K);
    REP(i,K) cin>>A[i];
    ll l=1,r=1LL<<50;
    auto f=[&](ll x){
        REP(i,K){
            x=(x/A[i])*A[i];
        }
        if(x==2) return true;
        return false;
    };
    while(l+1<r){
        ll mid=(l+r)/2,tmp=mid;
        bool S=false;
        REP(i,K){
            tmp=(tmp/A[i])*A[i];
            if(tmp<2){//明らかに少ない
                l=mid;
                S=true;
            }
        }
        if(S) continue;
        r=mid;
    }
    if(!f(r)){//rがあり得る下界になる
        cout<<-1<<endl;
        return 0;
    }
    ll L=r,R=1LL<<50;
    while(L+1<R){
        ll MID=(L+R)/2;
        if(f(MID)) L=MID;
        else R=MID;
    }
    cout<<r<<" "<<L<<endl;
}

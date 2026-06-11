#include<bits/stdc++.h>
#define REP(i,n) for(int i=0,i##_len=(n);i<i##_len;++i)
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define All(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;

int main(){
    int N;cin>>N;
    vector<ll> A(N),B(N);
    ll ans=0,tmp=INT_MAX;
    REP(i,N){
        cin>>A[i]>>B[i];
        ans+=B[i];
        if(A[i]>B[i]) tmp=min(tmp,B[i]);
    }
    if(A==B){
        cout<<0<<endl;
        return 0;
    }
    ans-=tmp;
    cout<<ans<<endl;
}
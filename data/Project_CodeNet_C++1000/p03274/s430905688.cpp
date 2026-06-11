#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using Graph=vector<vector<int>>;
typedef long long ll;

int main(){
    int N,K;
    cin>>N>>K;
    vector<ll>X(N);
    rep(i,N){
        cin>>X.at(i);
    }
    ll ans=20000000000;
    for(int i=0;i<=N-K;i++){
        ll a=min(abs(X[i])+abs(X[i+K-1]-X[i]),abs(X[i+K-1])+abs(X[i+K-1]-X[i]));
        ans=min(a,ans);
    }
    cout<<ans<<endl;
}
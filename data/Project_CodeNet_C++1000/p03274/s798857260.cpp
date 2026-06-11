#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
typedef long long ll;
const ll INF = 1e+18;

int main(){
    int N,K;
    cin >> N >> K;
    vector<ll> x(N);
    rep(i,N) cin >> x[i];
    ll ans=INF;
    ll dist;
    rep(i,N-K+1){
        if(x[i+K-1]<=0) dist=abs(x[i]);
        else if(x[i]<0) dist=min(abs(x[i])+abs(x[i+K-1]-x[i]),abs(x[i+K-1])+abs(x[i+K-1]-x[i]));
        else dist=x[i+K-1];
        ans=min(dist,ans);
    }

    cout << ans << endl;

}

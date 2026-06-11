#include <bits/stdc++.h>
using namespace std;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define INF 100000000
typedef long long ll;
 
int main(){
    ll N,M,X,Y;
    cin>>N>>M>>X>>Y;
    VL x(N),y(M);
    ll ma=-INF,mi=INF;
    rep(i,0,N){cin>>x[i];ma=max(ma,x[i]);}
    rep(i,0,M){cin>>y[i];mi=min(mi,y[i]);}
    //cout<<ma<<" "<<mi<<" ";
    ll Z=mi;
    if(Z>ma&&X<Z&&Z<Y){cout<<"No War"<<endl;return 0;}
    cout<<"War"<<endl;
    return 0;
}
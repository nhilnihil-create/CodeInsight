#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
const int INF=1145141919,MOD=1e9+7;
const long long LINF=8931145141919364364,LMOD=998244353;
// const int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};

int main(){
    int n; cin>>n;
    int t[n+1]={}; rep(i,n){cin>>t[i+1],t[i+1]*=2;}
    rep(i,n) t[i+1]+=t[i];
    int v[n]; rep(i,n){cin>>v[i],v[i]*=2;}
    int vv[n+1]={}; rep(i,n-1) vv[i+1]=min(v[i],v[i+1]);
    int sp[40010]; rep(i,40010) sp[i]=INF;
    rep(i,n){
        for(int j=t[i];j<=t[i+1];j++){
            sp[j]=min(sp[j],v[i]);
        }
    }
    rep(i,40010){
        rep(j,n+1){
            sp[i]=min(sp[i],vv[j]+abs(i-t[j]));
        }
    }
    double ans=0;
    rep(i,t[n]){
        ans+=min(sp[i],sp[i+1])+1.0*abs(sp[i]-sp[i+1])/2;
    }
    printf("%.10f\n",ans/4);
    return 0;
}

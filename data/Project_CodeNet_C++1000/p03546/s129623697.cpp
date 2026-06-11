#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=1000000007;
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
const int mmax=1000009;

int main(void){
    int h,w;
    cin>>h>>w;
    int C[10][10];
    rep(i,10) rep(j,10) cin>>C[i][j];
    rep(k,10) rep(i,10) rep(j,10){
        C[i][j]=min(C[i][j],C[i][k]+C[k][j]);
    }
    /*rep(i,10){
        rep(j,10){
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }*/
    int count[10];
    rep(i,10) count[i]=0;
    rep(i,h) rep(j,w){
        int a;
        cin>>a;
        if(a==-1) continue;
        count[a]++;
    }
    long long ans=0;
    rep(i,10){
        if(i==1) continue;
        ans+=count[i]*C[i][1];
        //cout<<i<<" "<<ans<<endl;
    }
    cout<<ans<<endl;
    return 0;
}

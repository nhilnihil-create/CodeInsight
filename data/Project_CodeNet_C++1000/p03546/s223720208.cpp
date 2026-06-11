#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    int h,w;
    cin>>h>>w;
    int c[10][10];
    rep(i,10) rep(j,10) cin>>c[i][j];
    rep(k,10){
        rep(i,10){
            rep(j,10){
                c[i][j]=min(c[i][j],c[i][k]+c[k][j]);
            }
        }
    }
    int ans=0;
    rep(i,h){
        rep(j,w){
            int a;
            cin>>a;
            if(a==-1) continue;
            ans+=c[a][1];
        }
    }

    cout<<ans<<endl;
}


 
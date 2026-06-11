#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
ll mod=1e9+7;
using P=pair<int,int>;
struct op{int a,b,c,d;};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,C;cin>>N>>C;
    int d[30][30],t[3][30];
    rep(i,C)rep(j,C)cin>>d[i][j];
    rep(i,3)rep(j,30)t[i][j]=0;
    rep(i,N)rep(j,N){
        int x;cin>>x;
        t[(i+j)%3][x-1]++;
    }
    int ans=1<<30;
    rep(i,C)rep(j,C){
        if(i==j)continue;
        rep(k,C){
            if(i==k||j==k)continue;
            int tt=0;
            rep(l,C)tt+=d[l][i]*t[0][l];
            rep(l,C)tt+=d[l][j]*t[1][l];
            rep(l,C)tt+=d[l][k]*t[2][l];
            if(ans>tt)ans=tt;
        }
    }
    cout<<ans<<endl;
    return 0;
}

#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define sp(n) cout << fixed << setprecision(n)
typedef long long ll;
using namespace std;
int main(void){
    int N,C;cin>>N>>C;
    int D[C][C],c[3][31];
    rep(i,3)rep(j,31)c[i][j]=0;
    rep(i,C)rep(j,C) cin>>D[i][j];
    rep(i,N)rep(j,N){
        int x;cin>>x;
        c[(i+j)%3][x-1]++;
    }
    int res=1e+9+1;
    rep(i,C)rep(j,C)rep(k,C){
        if(i==j||j==k||i==k)continue;
        int tot=0;
        rep(l,C) tot+=D[l][i]*c[0][l];
        rep(l,C) tot+=D[l][j]*c[1][l];
        rep(l,C) tot+=D[l][k]*c[2][l];
        res=min(res,tot);
    }
    cout<<res<<endl;
} 

#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
   int n,m,q;cin>>n>>m>>q;
   vector<vector<ll>> a(n+10,vector<ll>(n+10,0)),b(n+10,vector<ll>(n+10,0));
   rep(i,m){
       int l,r;cin>>l>>r;
       a[l][r]++;
   }
   
   for(int i=0;i<=n;i++){
       for(int j=0;j<=n;j++){
           b[i][j+1]=b[i][j]+a[i][j+1];
       }
   }
   rep(i,q){
       int p,q;cin>>p>>q;
       int res=0;
       for(int j=p;j<=q;j++){
           res+=(b[j][q]-b[j][p-1]);
       }
       cout<<res<<endl;
   }
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int n,m,q;
  cin>>n>>m>>q;
  int a[n][n];
  rep(i,0,n){
    rep(j,0,n){
      a[i][j]=0;
    }
  }
  rep(i,0,m){
    int l,r;
    cin>>l>>r;
    a[l-1][r-1]++;
  }
  int sum[n+1][n+1];
  rep(i,0,n+1){
    sum[0][i]=0;
    sum[i][0]=0;
  }
  rep(i,0,n){
    rep(j,0,n){
      sum[i+1][j+1]=sum[i+1][j]+sum[i][j+1]-sum[i][j]+a[i][j];
    }
  }
  rep(i,0,q){
    int b,c;
    cin>>b>>c;
    cout<<sum[c][c]-sum[c][b-1]-sum[b-1][c]+sum[b-1][b-1]<<endl;
  }
}
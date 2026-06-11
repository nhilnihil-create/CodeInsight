#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair <int,int> P;

int a[3][35];

int main(){
  int N,C;
  cin>>N>>C;
  int D[35][35];
  rep(i,C) rep(j,C){
    cin>>D[i][j];
  }
  int c[505][505];
  rep(i,N) rep(j,N){
    cin>>c[i][j];
    c[i][j]--;
  }
  rep(h,N) rep(w,N){
    if((h+w)%3==0)
      a[0][c[h][w]]++;
    else if((h+w)%3==1)
      a[1][c[h][w]]++;
    else
      a[2][c[h][w]]++;
  }
  int ans=1e9;
  rep(i,C) rep(j,C) rep(k,C){
    if(i==j||i==k||j==k) continue;
    int sum=0;
    rep(l,3) rep(m,C){
      if(l==0)
	sum+=a[l][m]*D[m][i];
      else if(l==1)
	sum+=a[l][m]*D[m][j];
      else
	sum+=a[l][m]*D[m][k];
    }
    ans=min(sum,ans);
  }
  cout<<ans<<endl;
  return 0;
}
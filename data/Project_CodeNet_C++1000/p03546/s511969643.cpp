#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using vll = vector<ll> ;
#define all(v) v.begin(),v.end()

int dist[10][10];

void wasyahuro(){
  rep(k,10){
    rep(i,10){
      rep(j,10){
        dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
      }
    }
  }
}

int main(){
  int H,W;cin>>H>>W;
  rep(i,10)rep(j,10)cin>>dist[i][j];
  int A[H][W];
  rep(i,H)rep(j,W)cin>>A[i][j];
  wasyahuro();
  //rep(i,10){rep(j,10){cout<<dist[i][j];}cout<<endl;};
  ll ans=0;
  rep(i,H){
    rep(j,W){
      if(A[i][j]==-1) continue;
      ans += dist[A[i][j]][1];
    }
  }
  cout << ans << endl;
}
#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const double INF=1e9;

int main(){
  int n;
  cin>>n;
  vector<int>t(n),v(n);
  int T=0;
  rep(i,n){
    cin>>t[i];
    T+=t[i];
  }
  rep(i,n)cin>>v[i];

  //初期化
  vector<double>maxV(2*T+1,INF);
  int now=0;
  rep(i,n){
    rep(j,2*t[i]){
      chmin(maxV[now],(double)v[i]);
      chmin(maxV[now+1],(double)v[i]);
      now++;
    }
  }

  //各点の位置を決める
  maxV[0]=maxV[2*T]=0;

  rep(i,2*T){
    chmin(maxV[i+1],maxV[i]+0.5);
  }

  for(int i=2*T; i>0; --i){
    chmin(maxV[i-1],maxV[i]+0.5);
  }

  //台形の面積を計算
  double ans=0;
  rep(i,2*T){
    ans+=(maxV[i]+maxV[i+1])*0.5/2;
  }
  printf("%.6f\n",ans);
}

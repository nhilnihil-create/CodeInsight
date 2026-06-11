#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (int)(n);i++)
using ll = long long;
const ll MOD=1000000007;
const long long INF = 1LL << 60;
const double pi=acos(-1.0);

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

ll H,W;

bool movable(ll sx,ll sy,ll gx,ll gy){
  if(gx>=W||gy>=H) return false;
  
  return true;
}

int main()
{
  cin>>H>>W;
  vector<vector<ll>> a(H,vector<ll>(W)); rep(i,H) rep(j,W) cin>>a[i][j];
  
  vector<vector<ll>> vec(0);
  rep(y,H){
    rep(x,W){
      if(a[y][x]%2==0) continue;
      if(movable(x,y,x+1,y)&&a[y][x+1]%2==1){
        a[y][x+1]++;
        vec.push_back({y,x,y,x+1});
        continue;
      }
      if(movable(x,y,x,y+1)&&a[y+1][x]%2==1){
        a[y+1][x]++;
        vec.push_back({y,x,y+1,x});
        continue;
      }
      if(movable(x,y,x+1,y)){
        a[y][x+1]++;
        vec.push_back({y,x,y,x+1});
        continue;
      }
      if(movable(x,y,x,y+1)){
        a[y+1][x]++;
        vec.push_back({y,x,y+1,x});
        continue;
      }
    }
  }
  
  cout<<vec.size()<<endl;
  for(auto p:vec){
    rep(i,4){
      if(i!=0) cout<<" ";
      cout<<p[i]+1;
    }
    cout<<endl;
  }
  return 0;
}

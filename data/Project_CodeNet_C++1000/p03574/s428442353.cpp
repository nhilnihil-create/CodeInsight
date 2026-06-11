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

bool is_ok(ll x,ll y){
  if(x<0||x>=W||y<0||y>=H) return false;
  return true;
}


int main()
{
  cin>>H>>W;
  vector<string> S(H); rep(i,H) cin>>S[i];
  
  rep(y,H){
    rep(x,W){
      if(S[y][x]=='#') continue;
      
      ll count=0;
      if(is_ok(x-1,y-1)&&S[y-1][x-1]=='#') count++;
      if(is_ok(x-1,y)&&S[y][x-1]=='#') count++;
      if(is_ok(x-1,y+1)&&S[y+1][x-1]=='#') count++;
      if(is_ok(x,y+1)&&S[y+1][x]=='#') count++;
      if(is_ok(x+1,y+1)&&S[y+1][x+1]=='#') count++;
      if(is_ok(x+1,y)&&S[y][x+1]=='#') count++;
      if(is_ok(x+1,y-1)&&S[y-1][x+1]=='#') count++;
      if(is_ok(x,y-1)&&S[y-1][x]=='#') count++;
      
      S[y][x]=(char)('0'+count);
    }
  }
  
  rep(i,H) cout<<S[i]<<endl;
  return 0;
}
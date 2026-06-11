#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lvector vector<ll>
#define cvector vector<char>
#define svector vector<string>
#define lque queue<ll>
#define lpque priority_queue<ll>
#define dlpque priority_queue<ll,lvector,greater<ll>>
#define P pair<ll,ll>
#define ALL(a) a.begin(),a.end()
#define rep(i,n) for(ll i=0; i<n; ++i)
#define print(a) cout << (a) << endl

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll h,w,ans=0;cin>>h>>w;
  vector<cvector> G(h,cvector(w));
  string s;
  queue<P> que;
  rep(i,h) {
    cin>>s;
    rep(j,w) {
      G[i][j]=s[j];
      if(s[j]=='#') que.push(P(i,j));
    }
  }
  bool operated=false;
  ll l,cnt,x,y;
  lvector dx{1,0,-1,0},dy{0,1,0,-1};
  P tag;
  while(que.size()) {
    operated=false;
    cnt=0,l=que.size();
    while(cnt<l) {
      tag=que.front();que.pop();
      x=tag.first,y=tag.second;
      rep(i,4) {
        if(  0<=x+dx[i]&&x+dx[i]<h&&0<=y+dy[i]&&y+dy[i]<w
           &&G[x+dx[i]][y+dy[i]]=='.') {
          G[x+dx[i]][y+dy[i]]='#';
          que.push(P(x+dx[i],y+dy[i]));
          operated=true;
        }
      }
      cnt++;
    }
    if(operated) ans++;
  }
  print(ans);
  return 0;
}
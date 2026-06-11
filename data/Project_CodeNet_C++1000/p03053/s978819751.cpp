#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const ll p=1000000007;
int main(){
  int h,w;
  cin >> h >> w;
  int k[h][w];
  rep(i,h)rep(j,w)k[i][j]=-1;
  queue<pair<int,int>> q;
  rep(i,h){
    string s;
    cin >> s;
    rep(o,w){
      if(s[o]=='#'){
        k[i][o]=0;
        q.push(make_pair(i,o));
      }
    }
  }
  int ans=0;
  while(q.size()!=0){
    pair<int,int> a=q.front();
    q.pop();
    int x=a.first,y=a.second;
    if(x!=0){
      if(k[x-1][y]==-1){
        k[x-1][y]=k[x][y]+1;
        ans=max(ans,k[x][y]+1);
        q.push(make_pair(x-1,y));
      }
    }
    if(x!=h-1){
      if(k[x+1][y]==-1){
        k[x+1][y]=k[x][y]+1;
        ans=max(ans,k[x][y]+1);
        q.push(make_pair(x+1,y));
      }
    }
    if(y!=0){
      if(k[x][y-1]==-1){
        k[x][y-1]=k[x][y]+1;
        ans=max(ans,k[x][y]+1);
        q.push(make_pair(x,y-1));
      }
    }
    if(y!=w-1){
      if(k[x][y+1]==-1){
        k[x][y+1]=k[x][y]+1;
        ans=max(ans,k[x][y]+1);
        q.push(make_pair(x,y+1));
      }
    }
  }
  cout << ans << endl;
}

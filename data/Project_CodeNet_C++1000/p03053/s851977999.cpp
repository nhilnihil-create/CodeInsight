#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007



int main(){
  
  int dx[] = {1,0,0,-1};
  int dy[] = {0,1,-1,0};
  int h,w;
  scanf("%d %d",&h,&w);
  vector<string> v(h);
  rep(i,h)cin >> v[i];
  queue<P> que;
  rep(i,h)rep(j,w)if(v[i][j] == '#')que.push(make_pair(i,j));
  ll res = 0;
  while(!que.empty()){
    queue<P> q;
    res++;
    while(!que.empty()){
      P ov = que.front();que.pop();
      rep(i,4){
        P nv = make_pair(ov.first+dy[i],ov.second+dx[i]);
        if(nv.first < 0 || nv.first >= h || nv.second < 0 || nv.second >= w)continue;
        if(v[nv.first][nv.second] == '#')continue;
        v[nv.first][nv.second] = '#';
        q.push(nv);
      }
    }
    que =  q;
  }
  res--;
  cout << res << endl;





  return 0;
}
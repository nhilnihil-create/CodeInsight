#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
ll gcd(int x, int y) { return (x % y)? gcd(y, x % y): y; }    //最大公約数
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }     //最小公倍数
using Graph = vector<vector<int>>;
ll inf=300000000000000000;
const double PI = 3.14159265358979323846;
int main(){
  int n;
  cin >> n;
  Graph g(n);
  rep(i,n-1){
    int a,b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  int dist[n];
  rep(i,n)dist[i]=1000000000;
  dist[0]=0;
  queue<int> q;
  q.push(0);
  int a=0,b=0;//a=0との距離が最大となる点
    //cout << 1 << endl;
  while(q.size()!=0){
    int u=q.front();
    q.pop();
    for(int v: g[u]){
      if(dist[v]>=1000000000){
        if(b<dist[u]+1){
          b=dist[u]+1;
          a=v;
        }
        dist[v]=dist[u]+1;
        q.push(v);
      }
    }
  }
  rep(i,n)dist[i]=1000000000;
  dist[a]=0;
  int ans=0;
  q.push(a);
  while(q.size()!=0){
    int u=q.front();
    q.pop();
    for(int v: g[u]){
      if(dist[v]>=1000000000){
        if(ans<dist[u]+1){
          ans=dist[u]+1;
        }
        dist[v]=dist[u]+1;
        q.push(v);
      }
    }
  }
  if(ans%3==1)cout << "Second" << endl;
  else cout << "First" << endl;
}

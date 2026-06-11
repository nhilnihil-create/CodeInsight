#include<iostream>
#include<queue>
#include<bitset>
#include<algorithm>
#include<climits>
#include<deque>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
#define fill(x,y) memset(x,y,sizeof(x))
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define dump(a) rep(i,a.size()){ cout<<a[i]<<" "; } cout<<endl;
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define INF INT_MAX/3
#define EPS 1e-7

// 各桁の和(point)を枝の重みとしたグラフを考える
// 求めるのは1~K(mod Kで0)の整数を点として、+1(重み1),x10(重み0)の遷移を枝としたグラフ上の、1->0の最短経路
// modKで同一視して良いのは、iとi+mKの遷移先がmodKとして同じになるからで、iとi+mKのグラフは同一視できるから
// 9+1で10になる遷移は、明らかに最短でないから最短経路には影響しない。
// dijkstra, BFSでもなく, 01BFSを使うとO(K)で求まる

int digitsum(ll n) {
  ll t = n;
  ll s = 0;
  while(t>0){
    s += t % 10;
    t = t / 10;
  }
  return s;
}

int main(){
  ll k;
  cin>>k;

  deque<P> d;
  d.push_front(P(1,1)); // n, cost
  vector<bool> visited(k,false);

  while(!d.empty()){
    P p = d.front(); d.pop_front();
    int i=p.first, score=p.second;
    if(i==0) {
      cout<<score<<endl;
      break;
    }
    visited[i]=true;
    // 遷移
    ll n0 = (i*10)%k;
    ll n1 = (i+1)%k;
    if(!visited[n0]) d.push_front(P(n0, score));
    if(!visited[n1]) d.push_back(P(n1, score+1));
  }
  return 0;
}



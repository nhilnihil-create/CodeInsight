#include<cstdio>
#include<queue>
#include<utility>
#include<cstring>
#include<stack>
#include<algorithm>
#include<cmath>
#include<iostream>
#define MAX_N 100001
#define INF 2147483647
#define REP(i,n) for(int i=0;i<(int)(n);i++)
void init(int n);
int find(int n);
void unite(int x,int y);
bool same(int x, int y);
int dx[4] = {1,0,0,-1};
int dy[4] = {0,1,-1,0};
using namespace std;
typedef pair<long long int,long long int> vect;
typedef pair<vect,long long int> seta;

long long int digitsum(long long int n)
{
  if(n==0)
    return 0;
  else
    return n%10+digitsum(n/10);
}

int main()
{
  deque<seta> que;
  long long int K,graph[100001],vortex,count,suchi,res;
  seta temps;
  vect x,y;
  cin >> K;
  REP(i,100001)graph[i] = INF;
  que.push_front(make_pair(make_pair(1,1),0));
  while(1){
    temps = que.front();
    que.pop_front();
    x = temps.first;
    count = temps.second;
    vortex = x.first;
    suchi = x.second;
    
    if(vortex == 0){
      cout << suchi << endl;
      return 0;
    }
    if(graph[vortex] == 0)
      continue;
    graph[vortex] = 0;
    que.push_back(make_pair(make_pair((vortex+1) % K,suchi+1),count+1));
    que.push_front(make_pair(make_pair((vortex*10) % K,suchi),count+1));
  }
  return 0;
}

int par[MAX_N];
int ranks[MAX_N];

//n要素で初期化
void init(int n){
  REP(i,n){
    par[i] = i;
    ranks[i] = 0;
  }

}

//木の根を求める
int find(int x){
  if(par[x] == x){
    return x;
  }else{
    return par[x] = find(par[x]);
  }
}

void unite(int x,int y){
  x = find(x);
  y = find(y);
  if(x == y) return ;
  if(ranks[x] < ranks[y]){
    par[x] = y;
  }else{
    par[y] = x;
    if(ranks[x] == ranks[y]) ranks[x]++;
  }
}

bool same(int x, int y){
  return find(x) == find(y);
}


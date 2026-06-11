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
typedef long long ll;
struct edge{
  int from,to,cost;
};
typedef vector<vector<edge> > AdjList;
AdjList graph;
typedef pair<int , int> P;
bool comp(const edge& e1, const edge& e2){
  return e1.cost < e2.cost;
}

long long int MOD = 1000000007;
long long int ruiseki[200001];
void ncrset(){
  ruiseki[0] = 1;
  for(int i=1;i<200001;i++){
    ruiseki[i] = (ruiseki[i-1] * i) % MOD;
  }
}

long long int powld(long long int x,long long int n,long long int mod){
  long long int ans = 1;
  while(n > 0){
    if((n&1) == 1){
      ans = (ans*x)  % mod;
    }
    x = (x*x) % mod;
    n >>= 1;
  }
  return ans % mod;
}


int main()
{
  ll N,K,A[100001],res=0;
  cin >> N;
  REP(i,N)cin >> A[i];
  ll sum[100001];
  sum[0] = 0;
  sum[1] = 1;
  for(int i=2;i<=100000;i++){
    sum[i] = (sum[i-1] + powld(i,MOD-2,MOD))%MOD;
  }
 
  ncrset();
  for(int i=1;i<=N;i++){
    res = ((res + (((((ruiseki[N]*(sum[N-i+1]-1))%MOD + ((sum[i])*ruiseki[N])%MOD))%MOD)*A[i-1])%MOD))%MOD;
  }
  cout << res << endl;
  
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


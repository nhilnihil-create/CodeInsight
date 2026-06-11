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
int main()
{
  int N,a[100],M,m,f,indm,indM,count=0;
  cin >> N;
  REP(i,N)cin >> a[i];
  f = 1;
  REP(i,N){
    if(a[i] < 0)
      f = 0;
  }
  if(f){
    cout << N-1 << endl;
    REP(i,N-1){
      cout << (i+1) << " " << (i+2) << endl;
    }
    return 0;
  }
  f = 1;
  REP(i,N){
    if(a[i] > 0)
      f = 0;
  }
  if(f){
    cout << (N-1) << endl;
    for(int i=N;i>1;i--){
      cout << i << " " << (i-1) << endl;
    }
    return 0;
  }
  M = -10E6-1;
  m = 10E6+1;
  REP(i,N){
    if(a[i] > M){
      M = max(M,a[i]);
      indM = i;
    }
    if(a[i] < m){
      m = min(m,a[i]);
      indm = i;
    }
  }
  if(abs(M) >= abs(m)){
    REP(i,N){
      if(a[i] < 0)
        count++;
    }
    cout << (N-1 + count) << endl;
    REP(i,N){
      if(a[i] < 0)
        cout << (indM+1) << " " << i+1 << endl;
    }
    REP(i,N-1){
      cout << (i+1) << " " << (i+2) << endl;
    }
    return 0;
  }else{
    REP(i,N){
      if(a[i] > 0)
        count++;
    }
    cout << (N-1 + count) << endl;
    REP(i,N){
      if(a[i] > 0)
        cout << (indm+1) << " " << i+1 << endl;
    }
    for(int i=N;i>1;i--){
      cout << (i) << " " << (i-1) << endl;
    }
    return 0;
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


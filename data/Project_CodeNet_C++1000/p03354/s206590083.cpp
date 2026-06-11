#include <bits/stdc++.h>

#define ST_ARR_LEN(array) (sizeof(array)/sizeof(*array))
#define MOD 1000000007

using namespace std;

using ll = long long;
const ll MAX = LLONG_MAX;
const ll MIN = LLONG_MIN;

typedef stack<ll> llStack;
typedef queue<ll> llQueue;
typedef vector<ll> llVector;
typedef list<ll> llList;

typedef struct S{
  int a;
  int b;
} Object;

int par[100000];
void init(int n){
  for(int i=0;i<n;i++){
    par[i] = i;
  }
}
int root(int x){
  if(par[x] == x){
    return x;
  }else{
    return par[x] = root(par[x]);
  }
}
bool same(int x, int y){
  return root(x) == root(y);
}
void unite(int x, int y){
  x = root(x);
  y = root(y);
  if(x == y) return;
  par[x] = y;
}

int main(){
  ll N, M;
  cin >> N >> M;
  ll c[N];
  for(int i=0;i<N;i++){
    cin >> c[i];
  }
  ll x[M], y[M];
  for(int i=0;i<M;i++){
    cin >> x[i] >> y[i];
  }
  
  init(N);
  for(int i=0;i<M;i++){
    unite(c[x[i]-1]-1, c[y[i]-1]-1);
  }
  ll ans = 0;
  for(int i=0;i<N;i++){
    if(same(i, c[i]-1)){
      ans++;
    }
  }
  
  cout << ans << endl;
}
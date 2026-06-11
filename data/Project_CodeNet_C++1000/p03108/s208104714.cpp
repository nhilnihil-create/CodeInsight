#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 100005
#define INF 1000000005LL
//#define INF 1e18
#define MOD 1000000007

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int par[SIZE]; //親
int rnk[SIZE]; //木の深さ
map<int,ll> M; //親がiである木の頂点数

ll s;

//初期化(n要素0オリジン)
void init(int n){
  for(int i=0;i<n;i++){
    par[i] = i;
    rnk[i] = 0;
    M[i] = 1;
  }
}

//xの根を求める
int find(int x){
  if(par[x] == x){
    return x;
  }else{
    return par[x] = find(par[x]);
  }
}

//x,yの属する集合を併合
void unite(int x,int y){
  x = find(x);
  y = find(y);
  if(x == y)return;

  //違う集合だったとき
  ll a = M[par[x]];
  ll b = M[par[y]];

  if(rnk[x] < rnk[y]){
    par[x] = y;
  }else{
    par[y] = x;
    if(rnk[x] == rnk[y])rnk[x]++;
  }

  M[par[x]] = M[par[y]] = a+b;
  s -= a*b;
  
}

int n,m;
int a[SIZE],b[SIZE];
ll c[SIZE];

int main(){
  cin >> n >> m;
  s = (ll)n*(n-1)/2;
  rep(i,0,m){
    cin >> a[i] >> b[i];
  }
  init(n);
  for(int i=m-1;i>=0;i--){
    c[i] = s;
    unite(a[i],b[i]);
  }
  rep(i,0,m){
    cout << c[i] << endl;
  }

  return 0;
}

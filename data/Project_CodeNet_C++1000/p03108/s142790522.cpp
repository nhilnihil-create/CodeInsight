#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 100005
#define INF 1000000005LL
//#define INF 1e18
#define MOD 1000000007

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int n,m;
int a[SIZE],b[SIZE];
ll ans;
ll c[SIZE];

int par[SIZE]; //親
int rnk[SIZE]; //木の深さ
ll sz[SIZE]; //木の大きさ

//初期化(n要素0オリジン)
void init(int n){
  for(int i=0;i<n;i++){
    par[i] = i;
    rnk[i] = 0;
    sz[i] = 1;
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

  if(rnk[x] < rnk[y]){
    par[x] = y;
  }else{
    par[y] = x;
    if(rnk[x] == rnk[y])rnk[x]++;
  }
  ans -= sz[x]*sz[y];
  sz[x] = sz[y] = sz[x]+sz[y];
}

int main(){
  cin >> n >> m;
  ans = ((ll)n)*((ll)(n-1))/2LL;
  c[m] = ans;
  rep(i,0,m){
    cin >> a[i] >> b[i];
    a[i]--;b[i]--;
  }
  init(n);
  for(int i=m-1;i>=0;i--){
    unite(a[i],b[i]);
    c[i] = ans;
  }
  rep(i,1,m+1){
    cout << c[i] << endl;
  }

  return 0;
}

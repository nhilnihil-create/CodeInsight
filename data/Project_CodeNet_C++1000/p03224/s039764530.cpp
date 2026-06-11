#include<bits/stdc++.h>
#define MAX_N 100001
#define INF_INT 2147483647
#define INF_LL 9223372036854775807
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> P;
void init(int n);
int find(int n);
void unite(int x,int y);
bool same(int x, int y);
ll bpow(ll,ll,ll);
typedef vector<int> vec;
typedef vector<vec> mat;
mat mul(mat &A,mat &B);
mat pow(mat A,ll n);
int dx[4] = {1,0,0,-1};
int dy[4] = {0,1,-1,0};
const int MOD = 1000000007;

int main()
{
  int N,k;
  cin >> N;
  for(int i=1;i<=10000;i++){
    if(2*N == i*(i+1)){
      k = i;
      break;
    }
    if(i == 10000){
      cout << "No" << endl;
      return 0;
    }
  }
  vector<vector<int> >G(k+1,vector<int>(0));
  int cn=1;
  REP(i,k){
    for(int j=i+1;j<k+1;j++){
      G[i].push_back(cn);
      G[j].push_back(cn);
      cn++;
    }
  }
  cout << "Yes" << endl;
  cout << k+1 << endl;
  REP(i,k+1){
    cout << k << " ";
    REP(j,G[i].size())
      cout << G[i][j] << " ";
    cout << endl;
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

ll bpow(ll a, ll n,ll mod){
  int i = 0;
  ll res=1;
  while(n){
    if(n & 1)
      res = (res*a) % mod;
    a = (a*a) % mod;
    n >>= 1;
  }
  return res;
}
mat mul(mat &A, mat &B){
  mat C(A.size(),vec(B[0].size()));
    REP(i,A.size())REP(k,B.size())REP(j,B[0].size()){
    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
  }
  return C;
}

mat pow(mat A,ll n)
{
  mat B(A.size(),vec(A.size()));
  REP(i,A.size()){
    B[i][i] = 1;
  }
  while(n > 0){
    if ( n & 1) B = mul(B,A);
    A = mul(A,A);
    n >>= 1;
  }
  return B;
}

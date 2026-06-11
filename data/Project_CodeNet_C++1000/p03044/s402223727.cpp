#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define ll int64_t
#define _GLIBCXX_DEBUG
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
//約数列挙(√N)
vector< int64_t > divisor(int64_t n) {
  vector< int64_t > ret;
  for(int64_t i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
  return (ret);
}
//素因数分解(√N)
map< int64_t, int > prime_factor(int64_t n) {
  map< int64_t, int > ret;
  for(int64_t i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}
//素数テーブル(NloglogN)
vector< bool > prime_table(int n) {
  vector< bool > prime(n + 1, true);
  if(n >= 0) prime[0] = false;
  if(n >= 1) prime[1] = false;
  for(int i = 2; i * i <= n; i++) {
    if(!prime[i]) continue;
    for(int j = i + i; j <= n; j += i) {
      prime[j] = false;
    }
  }
  return prime;
}
//二項係数(K)
template< typename T >
T binomial(int64_t N, int64_t K) {
  if(K < 0 || N < K) return 0;
  T ret = 1;
  for(T i = 1; i <= K; ++i) {
    ret *= N--;
    ret /= i;
  }
  return ret;
}
//二項係数テーブル(N^2)
template< typename T >
vector< vector< T > > binomial_table(int N) {
  vector< vector< T > > mat(N + 1, vector< T >(N + 1));
  for(int i = 0; i <= N; i++) {
    for(int j = 0; j <= i; j++) {
      if(j == 0 || j == i) mat[i][j] = 1;
      else mat[i][j] = mat[i - 1][j - 1] + mat[i - 1][j];
    }
  }
  return mat;
}
//unionfind
struct UnionFind {
  vector< int > data;
 
  UnionFind(int sz) {
    data.assign(sz, -1);
  }
 
  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return (false);
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }
 
  int find(int k) {
    if(data[k] < 0) return (k);
    return (data[k] = find(data[k]));
  }
 
  int size(int k) {
    return (-data[find(k)]);
  }
};

void dfs(vector<vector<pair<int,int>>> &g,int i,vector<int> &ans,int sgn){
  if(ans.at(i)!=-1)return;
  ans.at(i)=sgn;
  rep(j,g.at(i).size()){
    int now=sgn+g.at(i).at(j).second;
    now%=2;
    dfs(g,g.at(i).at(j).first,ans,now);
  }
}
int main(){
  int n;
  cin >> n;
  vector<vector<pair<int,int>>> g(n);
  rep(i,n-1){
    int x,y,z;
    cin >> x >> y >> z;
    x--;
    y--;
    z%=2;
    g.at(x).push_back(make_pair(y,z));
    g.at(y).push_back(make_pair(x,z));
  }
  vector<int> ans(n,-1);
  dfs(g,0,ans,1);
  rep(i,n)
    cout << ans.at(i) << endl;
}
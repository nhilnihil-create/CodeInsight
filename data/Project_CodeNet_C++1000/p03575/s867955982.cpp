#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using pll = pair<long long, long long>;
const int INF = 1<<29;

const int MOD = 1000000007;
long long ruizyou(long long m,long long n){
  if(m == 0)return 0;
  if(m == 1)return 1;
  long long ans = 1;
  long long tmp = m;
  for(int i=0;i<=30;i++){
    if(n & (1<<i)){
      ans *= tmp;
      ans %= MOD;
    }
    tmp *= tmp;
    tmp %= MOD;
  }
  return ans;
}
long long kaizyou(long long x){
  if(x == 0)return 1;
  return x * kaizyou(x-1) % MOD;
}
long long comb(long long x,long long y){
  long long bunsi = kaizyou(x);
  long long bunbo = kaizyou(x-y) * kaizyou(y) % MOD;
  return bunsi * ruizyou((int)bunbo,MOD-2) % MOD;
}
struct unionfind{
  vector<int> par;
  unionfind(int n){
    par = vector<int>(n);
    for(int i=0;i<n;i++){
      par.at(i) = i;
    }
  }
  int root(int x){
    if(par.at(x) == x)return x;
    return root(par.at(x));
  }
  void unite(int x,int y){
    int rx = root(x);
    int ry = root(y);
    if(rx == ry)return;
    par.at(ry) = rx;
  }
  bool same(int x,int y){
    return root(x) == root(y);
  }
};

int main(){
  int n,m;
  cin >> n >> m;
  vector<int> a(m),b(m);
  for(int i=0;i<m;i++){
    cin >> a.at(i) >> b.at(i);
  }
  int ans = 0;
  for(int i=0;i<m;i++){
    unionfind tree(n);
    bool flag = false;
    for(int j=0;j<m;j++){
      if(i != j){
        tree.unite(a.at(j)-1,b.at(j)-1);
      }
    }
    for(int j=1;j<n;j++){
      if(!tree.same(0,j))flag = true;
    }
    if(flag)ans++;
  }
  cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
using PP = pair<int,pair<int,int>>;
using T = tuple<string,int,int>;
const string EMP = " ";
const ll INF = 1LL<<60;
const ll MOD = 1000000007;

ll n, ans = 0;

int chk(ll x){
  map<int, int> mp;
  while(x){
    mp[x%10]++;
    x /= 10;
  }
  int res = 0;
  if(mp.size() == 3) res++;
  return res;
}

void dfs(ll x){
  if(x > n) return;
  ans += chk(x);
  for(int i = 3; i <= 7; i += 2){
    x *= 10;
    x += i;
    dfs(x);
    x /= 10;
  }
}

int main(){
  cin >> n;
  dfs(0);
  cout << ans << endl;
  return 0;
}

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

int main(){
  int n; cin >> n;

  vector<int> h(n);
  rep(i,n) cin >> h[i];

  int ans = 0;

  int memo = 0;
  for(int i = 0; i < n; i++){
    if(memo >= h[i]){
      memo = h[i];
    }else{
      ans += h[i] - memo;
      memo = h[i];
    }
  }
  cout << ans << endl;
  return 0;
}

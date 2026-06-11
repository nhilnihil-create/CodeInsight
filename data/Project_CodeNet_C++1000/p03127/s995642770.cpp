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

int gcd(int a, int b){
  if(a % b == 0) return b;
  return gcd(b, a%b);
}

int main(){
  int n; cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  int ans = a[0];
  for(int i = 1; i < n; i++){
    ans = gcd(ans,a[i]);
  }
  cout << ans << endl;
  return 0;
}

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
  if(a == 0) return b;
  if(b == 0) return a;
  if(a % b == 0) return b;
  return gcd(b, a%b);
}

int main(){
  int n; cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  vector<int> left(n+1), right(n+1);
  for(int i = 0; i < n; i++) left[i+1] = gcd(left[i], a[i]);
  for(int i = n-1; i >= 0; i--) right[i] = gcd(right[i+1], a[i]);
  int ans = 0;
  for(int i = 0; i < n; i++){
    int now = gcd(left[i], right[i+1]);
    ans = max(ans, now);
  }
  cout << ans << endl;
  return 0;
}

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(int i = 0; i < n; i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
int digit_sum(int n){
   if(n < 10)  return n;
   return digit_sum(n/10) + n%10;
}

int main() {
  int n,a,b;
  cin >> n >> a >> b;
  int ans = 0;
  
  rep(i, n+1){
    if(digit_sum(i) >= a && digit_sum(i) <= b){
      ans += i;
    }
  }
  cout << ans << endl;
}

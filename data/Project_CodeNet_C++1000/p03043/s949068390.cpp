#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
template<class T> inline bool chmax(T& a, T b) {
  if (a < b) { a = b; return 1; }
  return 0; }
template<class T> inline bool chmin(T& a, T b) {
  if (a > b) { a = b; return 1; }
  return 0; }
ll MOD = 1000000007;

int main(void){
  long double n,k; cin >> n >> k;
  long double ans = 0;
  for(long double i = 1; i <= n; i++){
    long double l = 0;
    while(1){
      if(i * pow(2.,l) >= k){
        break;
      }
      else{
        l++;
      }
    }
    ans += (1./n)*pow(1./2.,l);
  }
  cout << setprecision(19);
  cout << ans << endl;
  return 0;
}

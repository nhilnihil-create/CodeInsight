#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 1; i <= (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main(){
  int a, b, k;
  cin >> a >> b >> k;
  
  int ans;
  int count=0;
  for(int i = min(a, b); i != 0; --i){
    if ((a % i == 0) && (b % i == 0)) count++;
    if (count == k){
      ans = i;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
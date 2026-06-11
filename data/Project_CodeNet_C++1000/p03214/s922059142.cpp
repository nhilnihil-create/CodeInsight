#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  int n;
  cin >>n;
  vector<int> a(n);
  rep(i,n) cin >>a[i];
  int sum = 0;
  rep(i,n) sum += a[i];
  int curMin = 1e8;
  int ans = 0;
  rep(i,n){
    int cur = abs(sum-n*a[i]);
    if(curMin>cur){
      curMin = cur;
      ans = i;
    }
  }
  cout << ans << endl;
  return 0;
}
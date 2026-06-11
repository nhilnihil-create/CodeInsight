#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >>n;
  vector<int> a(n);
  rep(i,n) cin >>a[i]; 
  vector<int> b(n);
  rep(i,n) cin >>b[i];
  int ans = 0;
  int total = 0;
  rep(i,n) total += a[i]+b[i];
  rep(i,n){
    int asum = 0;
    int bsum = 0;
    for(int j = i+1; j<n; j++) asum += a[j];
    for(int j = 0; j<i; j++) bsum += b[j];
    int sum = total - asum - bsum;
    if(sum>ans) ans = sum;
  }
  cout << ans << endl;
  return 0;
}
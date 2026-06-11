#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
ll mod= 1e9 + 7;



int main() {
  int n;
  cin >>n;
  int a[n];
  rep(i,n)cin >>a[i];
  int ans=a[0];
  for(int i=1;i<n;i++){
    ans=__gcd(ans,a[i]);
  }
  cout << ans << endl;
}
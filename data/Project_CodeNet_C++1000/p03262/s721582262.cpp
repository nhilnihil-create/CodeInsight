#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
ll mod= 1e9 + 7;



int main(){
  int n,x;
  cin >>n >>x;
  int a[n];
  rep(i,n)cin >> a[i];
  int ans=abs(x-a[0]);
  for(int i=1;i<n;i++){
    int g=abs(x-a[i]);
    ans=__gcd(g,ans);
  }
  cout << ans << endl;
}
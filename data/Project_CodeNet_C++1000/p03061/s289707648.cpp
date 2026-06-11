#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;

int main(){
  int n;cin >> n;
  vector<int> a(n),l(n+1),r(n+2);
  rep(i,n){
    cin >> a[i];
    l[i+1] = __gcd(l[i],a[i]);
  }
  for(int i = n;i >= 1;i--){
    r[i] = __gcd(r[i+1],a[i-1]);
  }
  //rep(i,n)  cout << r[i+1] << endl;
  int ans = 0;
  rep(i,n){
    ans = max(ans,__gcd(l[i],r[i+2]));
  }

  cout << ans << endl;
}
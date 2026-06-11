#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int gcd(int a, int b) {
  if(a%b==0) return b;
  else return gcd(b, a%b);
}

int main() {
  int n; cin>>n;
  int ans=1e9;
  vector<int> a(n);
  for(int i=0; i<n; i++) cin>>a[i];
  // おそらくユークリッドの互除法を使うことになる
  // 正直自信はない、が... 前から順番に最大公約数を求めてみる
  for(int i=0; i<a.size()-1; i++) {
    ans = min(ans,gcd(a[i],a[i+1]));
    if(ans==1) break;
  }
  cout << ans << endl;
}

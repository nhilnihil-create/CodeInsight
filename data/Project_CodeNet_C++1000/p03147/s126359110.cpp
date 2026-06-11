#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<n;i++)

int main() {
  int n; cin >> n; vector<int> a(n);
  rep(i,n)cin >> a[i];
  int ans=0;
  rep1(i,n){
    if(a[i]<a[i-1])ans+=a[i-1]-a[i];
  }
  ans+=a[n-1];
  cout << ans << endl;
}

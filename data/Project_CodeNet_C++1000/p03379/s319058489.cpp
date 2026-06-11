#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(obj) (obj).begin(), (obj).end()
#define bit(n) (1LL << (n))

typedef long long ll;

using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin>>n;
  vector<int> x(n), a(n);
  
  
  rep(i,n) {
    cin>>x[i];
    a[i] = x[i];
  }
  
  sort(all(a));
  
  rep(i,n) {
    if(x[i]<=a[n/2-1]) cout<<a[n/2]<<endl;
    else cout<<a[n/2-1]<<endl;
  }
}
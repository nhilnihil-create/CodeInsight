#include <bits/stdc++.h>
 
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(obj) (obj).begin(), (obj).end()
#define bit(n) (1LL << (n))
 
typedef long long ll;

using namespace std;

unsigned euclidean_gcd(unsigned a, unsigned b) {
  if(a < b) return euclidean_gcd(b, a);
  unsigned r;
  while ((r=a%b)) {
    a = b;
    b = r;
  }
  return b;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin>>n;
  
  vector<int> v(n);
  int ans=0;
  
  rep(i,n) {
    cin>>v[i];
  }
  
  rep(i,n) {
    int a = v[i];
    if (i==0) {
      int b = v[i+1];
      int div = euclidean_gcd(a,b);
      ans = div;
    } else {
      int div = euclidean_gcd(ans,a);
      ans = div;
    }
  }
  
  cout<<ans;
    
  return 0;
}
#include <bits/stdc++.h>
 
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(obj) (obj).begin(), (obj).end()
#define bit(n) (1LL << (n))
 
typedef long long ll;

using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int a,b;
  cin>>a>>b;
  
  int rem = b%a;
  
  if (rem==0) {
    cout<<a+b;
  } else {
    cout<<b-a;
  }
    
  return 0;
}
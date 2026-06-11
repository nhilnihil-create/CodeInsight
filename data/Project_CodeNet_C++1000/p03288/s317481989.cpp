#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(obj) (obj).begin(), (obj).end()
#define bit(n) (1LL << (n))

typedef long long ll;

using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int r;
  cin>>r;
  
  if(r<1200) {
    cout<<"ABC";
  } else if(r<2800) {
    cout<<"ARC";
  } else {
    cout<<"AGC";
  }
  
  return 0;
}
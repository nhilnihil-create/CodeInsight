#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<ll> v(n+1);
  v[0]=2, v[1]=1;
  if(n>=2) {
    for(int i=2; i<n+1; i++) {
      v[i]=v[i-1]+v[i-2];
    }
  }
  cout << v[n] << endl;
  return 0;
}
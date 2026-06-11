#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for(int i=0; i<n; i++) cin >> v[i];
  sort(v.rbegin(), v.rend());
  
  int a;
  int alice = 0, bob = 0;
  for(int i=1; i<=n; i++) {
    if(i%2==1) alice += v[i-1]; 
    else bob += v[i-1];
  }
  cout << alice-bob << endl;
  return 0;
}
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for(int i=0; i<n; i++) cin >> v[i];
  vector<int> w(n);
  for(int i=0; i<n; i++) cin >> w[i];
  
  int sum = 0;
  for(int i=0; i<n; i++) if(v[i] > w[i]) sum += v[i]-w[i];
  cout << sum << endl;
  return 0;
}
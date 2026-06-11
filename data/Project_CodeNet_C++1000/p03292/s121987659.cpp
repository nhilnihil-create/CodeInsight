#include <bits/stdc++.h>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ll long long
using namespace std;

int main() {
  vector<int> in(3);
  rep(i, 3) cin >> in[i];
  sort(in.begin(), in.end());
  
  cout << in[2] - in[0] << endl;
  
  
  return 0;
}

#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;


int main() {
  int n;
  cin >> n;
  vector<int> p(n);
  rep(i,n) cin >> p[i],
  sort(p.rbegin(),p.rend());
  int sum = p[0]/2;
  for(int i = 1; i < n; ++i){
    sum += p[i];
  }
  cout << sum << endl;
  return 0;
}
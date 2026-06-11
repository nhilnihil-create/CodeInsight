#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;


int main() {
  int n ;
  cin >> n;
  vector<int> l(n);
  rep(i,n) cin >> l[i];
  sort(l.rbegin(),l.rend());
  int sum = 0;
  for(int i = 1; i < n;++i) sum += l[i];
  if(l[0] < sum) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
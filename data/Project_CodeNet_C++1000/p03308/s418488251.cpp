#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  rep(i, n){
  	cin >> v.at(i);
  }
  int max_e = *max_element(v.begin(), v.end());
  int min_e = *min_element(v.begin(), v.end());
  cout << max_e - min_e << endl;
  return 0;
}
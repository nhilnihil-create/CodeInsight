#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#define ll long long
#define rep(i, a, b) for(int i = a; i < b; i++)
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  rep(i, 0, n) cin >> v[i];
  sort(v.begin(), v.end());
  int sum = 0;
  rep(i, 0, n-1) sum += v[i];
  if(sum <= v[n-1]) cout << "No\n";
  else cout << "Yes\n";
}

#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  map<int,int> d;
  int m;
  rep(i,n) {cin >> m; d[m] += 1;}
  cout << d.size() << endl;
}
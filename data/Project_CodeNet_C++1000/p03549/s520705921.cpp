#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, m;
  cin >> n >> m;
  int t=1;
  rep(i,m) t*=2;
  cout << (1900*m+(n-m)*100)*t << endl;
}

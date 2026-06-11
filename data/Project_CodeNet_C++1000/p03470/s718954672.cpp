#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (ll i = m; i < (n); i++)

using ll = long long;
using pii = pair<int, int>;
using Vi = vector<int>;

int main() {
  int n;
  cin >> n;
  set<int> S;
  rep(i,n){
    int d;
    cin >> d;
    S.insert(d);
  }
  cout << S.size() << endl;
} 
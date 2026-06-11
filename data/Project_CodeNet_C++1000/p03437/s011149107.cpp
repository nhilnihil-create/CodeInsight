#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (ll i = m; i < (n); i++)

using ll = long long;
using pii = pair<int, int>;
using Vi = vector<int>;

int main() {
  int x,y;
  cin >> x >> y;
  if(x%y==0){
    cout << -1 << endl;
  }
  else{
    cout << x << endl;
  }
} 
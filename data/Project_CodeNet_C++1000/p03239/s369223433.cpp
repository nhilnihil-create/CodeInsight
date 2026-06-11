#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
using namespace std;
using ll = long long;
using P = pair<int, int>;
 
int main() {
  int n,T;
  cin >> n >> T;
  int cost = 1001;
  rep(i,n){
    int c,t;
    cin >> c >> t;
    if(t <= T)cost = min(c,cost);
  }
  if(cost == 1001) cout << "TLE" << endl;
  else cout << cost << endl;
}


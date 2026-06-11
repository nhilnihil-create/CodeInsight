#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  int n,m,c;
  cin >> n >> m >> c;
  vector<int> b(m);
  rep(i,m) cin >> b.at(i);
    int cnt = 0;
  
  rep(i,n){
    int sum = c;
    rep(j,m){
      int a;
      cin >> a;
      sum+=a*b.at(j);
    }
    if(sum > 0)cnt++;
  } 
  cout << cnt << endl;
}

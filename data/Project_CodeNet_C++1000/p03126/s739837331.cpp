#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  int n,m;
  cin >> n >> m;
  vector<int> a(m);
  rep(i,n){
    int k;
    cin >> k;
    rep(j,k){
      int x;
      cin >> x;
      a.at(x-1)++;
    }
  }

  int cnt = 0;
  for(int i: a){
    if(i == n) cnt ++;
  }
  cout << cnt << endl;
}
  

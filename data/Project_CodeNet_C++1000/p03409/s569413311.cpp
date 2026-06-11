#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int n, z = 0;
  cin >> n;
  vector<tuple<int, int, int>> p(2 * n);
  rep(i, 2 * n) {
    int a, b;
    cin >> a >> b;
    p[i] = make_tuple(a, b, i / n);
  }
  vector<int> q(2 * n);
  sort(p.begin(), p.end());
  rep(i, 2 * n){
    int a, b, c;
    tie(a, b, c) = p[i];
    if (c == 0){
      q[b]++;
    }else{
      for (int j=b; j>=0; j--){
        if (q[j] == 1){
          z++;
          q[j] = 0;
          break;
        }
      }
    }
  }
  cout << z << endl;
  return 0;
}

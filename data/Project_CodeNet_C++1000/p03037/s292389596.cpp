#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int n,m;
  cin >> n >> m;
  int l1 = 0, r1 = 1000000;
  rep(i,m){
    int l, r;
    cin >> l >> r;
    l1 = max(l1, l);
    r1 = min(r1, r);
  }
  if(r1-l1 < 0) cout << 0 << endl;
  else cout << r1-l1+1 << endl;
}

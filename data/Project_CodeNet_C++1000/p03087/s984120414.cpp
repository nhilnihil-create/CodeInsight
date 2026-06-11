#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;

int main(){
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vi t(n);
  REP(i,1,n){
    t.at(i) += t.at(i-1);
    if (s.at(i-1) == 'A' && s.at(i) == 'C'){
      t.at(i)++;
    }
  }
  rep(i,q){
    int l, r;
    cin >> l >> r;
    l--; r--;
    int ans = t.at(r) - t.at(l);
    cout << ans << endl;
  }
  return 0;
}

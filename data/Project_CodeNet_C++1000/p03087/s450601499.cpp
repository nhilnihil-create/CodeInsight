#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main(){
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<int> sum(n+1, 0);
  rep(i, n){
    int add = 0;
    if(i > 0 && s.at(i) == 'C' && s.at(i-1) == 'A') add++;
    sum.at(i+1) = sum.at(i) + add;
  }
  rep(_q, q){
    int l, r;
    cin >> l >> r;
    cout << sum.at(r) - sum.at(l) << endl;
  }
  return 0;
}
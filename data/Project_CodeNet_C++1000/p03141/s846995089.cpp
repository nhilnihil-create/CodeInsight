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
  int n;
  cin >> n;
  vector<int> tp(n), ap(n);
  vector<pair<int, int>> vp(n);
  rep(i, n){
    int a, b;
    cin >> a >> b;
    tp.at(i) = a; ap.at(i) = b;
    vp.at(i) = make_pair(a+b, i);
  }
  sort(vp.rbegin(), vp.rend());
  ll ansa = 0, ansb = 0;
  rep(i, n){
    if(i % 2 == 0) ansa += tp.at(vp.at(i).second);
    else ansb += ap.at(vp.at(i).second);
  }
  cout << ansa - ansb << endl;
  return 0;
}
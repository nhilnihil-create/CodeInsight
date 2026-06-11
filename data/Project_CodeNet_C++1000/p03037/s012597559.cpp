#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  
  int r,l;
  int rmax = 0, lmin = n;
  vector<int> c(n+1);
  
  for(int i = 0; i < m; ++i){
    cin >> r >> l;
    rmax = max({rmax,r});
    lmin = min({lmin,l});
  }
  
  int res = max({lmin-rmax+1,0});
  
  cout << res << endl;
}
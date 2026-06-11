#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n,m,x; cin >> n >> m >> x;
  vector<int> a(m); rep(i,m) cin >> a[i];
  int l=0,r=0;

  for(int i = 0;i<x;i++)
    rep(j,m)
      if(i==a[j]) l++;

  for(int i = x+1;i<=n;i++)
    rep(j,m)
      if(i==a[j]) r++;

  int cost;
  if(l>=r) cost = r;
  else cost = l;

  cout << cost << endl;
  
  return 0;
}

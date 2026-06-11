#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  int n, m;
  cin >> n >> m;
  vector<tuple<int,int,int>> a(m+1);
  for(int i=1; i<=m; i++) {
    int p, y;
    cin >> p >> y;
    a[i]=make_tuple(p,y,i);
  }
  sort(rng(a));
  for(int i=1; i<=m; i++) {
    if(get<0>(a[i-1])!=get<0>(a[i])) {
      get<1>(a[i])=1;
    }
    else get<1>(a[i])=get<1>(a[i-1])+1;
  }
  for(int i=1; i<=m; i++) {
    int x=get<0>(a[i]), y=get<1>(a[i]), z=get<2>(a[i]);
    get<0>(a[i])=z;
    get<1>(a[i])=x;
    get<2>(a[i])=y;
  }
  sort(rng(a));
  for(int i=1; i<=m; i++) printf("%06d%06d\n", get<1>(a[i]), get<2>(a[i]));
  return 0;
}
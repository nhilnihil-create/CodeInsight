#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
const int MX = 200005;
int h, w, n, x, y, e;
set<int> st[MX];
int main(){
  int a, b;
  scanf("%d%d%d", &h, &w, &n);
  rep(i,n){
    scanf("%d%d", &x, &y);
    x--; y--;
    st[x].insert(y);
  }
  st[h].insert(0);
  for(int i=1; i<=h; i++){
    if(st[i].upper_bound(e) != st[i].begin()) return 0*printf("%d\n",i);
    if(st[i].find(e+1) == st[i].end()) e++;
  }
}
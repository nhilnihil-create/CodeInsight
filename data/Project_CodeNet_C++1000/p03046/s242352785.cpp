#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define rrep(i, n) for(int i = n-1; i >= 0; --i)
using namespace std;
using v1i = vector<int>;

int main(){
  int a = -1, m, k; scanf("%d %d", &m, &k);
  v1i v;
  if(k == 0) rep(i, 1 << m) rep(j, 2) v.push_back(i);
  else if(m > 1 && k < (1 << m)){
    v.push_back(k);
    rep(i, (1 << m)) if(i != k) v.push_back(i);
    v.push_back(k);
    rrep(i, (1 << m)) if(i != k) v.push_back(i);
  }
  if(v.size() == 0) printf("%d\n", a);
  else{
    rep(i, v.size()){
      printf("%d", v[i]);
      if(i == v.size()-1) printf("\n");
      else printf(" ");
    }
  }
  return 0;
}
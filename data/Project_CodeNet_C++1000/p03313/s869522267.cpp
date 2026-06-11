#include <bits/stdc++.h>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define ALL(x)      begin(x),end(x)

using namespace std;
using vecint = vector<int>;
using ll = int64_t;

int main()
{
  int n;
  cin>>n;
  vecint a(1<<n);
  for(auto&& e:a)cin>>e;
  auto fst = a;
  vecint snd(1<<n,0);
  vecint tmp(4);
  REP(i,n)REP(j,1<<n) {
    if ((j>>i)&1) {
      tmp[0] = fst[j];
      tmp[1] = snd[j];
      tmp[2] = fst[j^(1<<i)];
      tmp[3] = snd[j^(1<<i)];
      sort(ALL(tmp),greater<int>());
      fst[j] = tmp[0];
      snd[j] = tmp[1];
    }
  }
  vecint res(1<<n);
  REP(i,1<<n){
    res[i] = fst[i] + snd[i];
    if (i) {
      res[i] = max(res[i], res[i-1]);
      cout<<res[i]<<endl;
    }
  }
  return 0;
}

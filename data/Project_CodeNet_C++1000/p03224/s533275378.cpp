/*
How to lambda
  ex) sort(ALL(cont),[](dat a,dat b){return a.l<b.l;});
lower_bound/upper_bound
  1 2 2 2 3 3 
    ^lb   ^ub */
#include <bits/stdc++.h>
#define BR "\n"
#define REP(i,n) for(int (i)=0;(i)<(n);++(i))
#define ALL(cont) begin(cont),end(cont)
#define AS_MOD(a,b) ((((a) % (b) ) + (b)) % (b))
#define FEACH(it,cont) for(auto (it) = begin(cont); it!=end(cont);++it)
#define FEACHR(it,cont) for(auto (it) = rbegin(cont); it!=rend(cont);++it)
#define pb push_back
#define pob push_back
#define LB(b,e,v) lower_bound(b,e,v)
#define UB(b,e,v) upper_bound(b,e,v)
#define fi first
#define se second
#define getll() ([](){ll s;scanf("%lld", &s);return s;})()
#define getld() ([](){ld s;scanf("%Lf", &s);return s;})()
#define prl(P) printf("%lld", P)
#define prd(P) printf("%.10Lf", P)
#define pr(P) printf(P)
using namespace std;
typedef long long ll;
typedef long double ld;
ll N;
vector<vector<ll> > ans;
void fail(){
  cout << "No" << endl;
  exit(0);
}
int main() {
  cout << fixed << setprecision(10);
  N = getll();
  ll k=0;
  REP(i,N+10)
    if (N*2==i*(i+1))
      k=i+1;
  if (k==0)
    fail();
  ans.resize(k);

  REP(i,k) {
    ll p=(k-1+k-i)*i/2;
    REP(j,k-i-1) {
      ans[i].pb(p+j);
      ans[i+j+1].pb(p+j);
    }
  }

  pr("Yes");
  pr(BR);
  cout << k << endl;
  REP(i,k) {
    prl(k-1);
    pr(" ");
    FEACH(it, ans[i]){
      prl(*it+1);pr(" ");
    }
    pr(BR);
  }
  return 0;
}

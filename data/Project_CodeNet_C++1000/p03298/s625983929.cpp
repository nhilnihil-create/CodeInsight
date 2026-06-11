#include <bits/stdc++.h>

#define REP(i,n) for(int i=0;i<(n);++i)
#define FORR(it,cont) for(auto it=rbegin(cont);it!=rend(cont);++it)
#define FOR(it,cont) for(auto it=begin(cont);it!=end(cont);++it)
#define ALL(cont) begin(cont), end(cont)
#define LB(b,e,v) lower_bound(b,e,v)
#define UB(b,e,v) upper_bound(b,e,v)
#define AS_MOD(a,b) ((((a) % (b) ) + (b)) % (b))
#define MODDING(a,b) (a) = AS_MOD(a,b)
#define MAXIMIZE(a, b) (a) = max((a),(b))
#define MINIMIZE(a, b) (a) = min((a),(b))

using namespace std;
typedef long long ll;
int N;
string P,Q;
string S2;
ll dptable[20][20];
ll doDP(int p, int q) {
  if (dptable[p][q]!=-1) {
    return dptable[p][q];
  }
  if (p == P.length() && q == Q.length()) {
    return dptable[p][q] = 1;
  }
  int i=p+q;
  ll val = 0;
  if (p < P.length() && S2[i] == P[p]) {
    val += doDP(p+1, q);
  }
  if (q < Q.length() && S2[i] == Q[q]) {
    val += doDP(p, q+1);
  }
  return dptable[p][q] = val;
}
int main(int argc, char **argv, char **envp) {
  string S;
  cin >> N >> S;
  S2 = S;
  reverse(S2.begin(), S2.end());
  S2.resize(N);
  //cout << S2 << endl;
  ll ans=0;
  for(int comb=0;comb< (1<<N);++comb) {
    P=Q="";
    for(int i=0;i<N;++i) {
      if((comb >> i) & 1 == 1) {
        P+=S[i];
      } else {
        Q+=S[i];
      }
    }
    memset(dptable,-1,sizeof(dptable));
    ans += doDP(0,0);
    //cout << P << " " << Q << endl;
  }
  cout << ans << endl;
  return 0;
}

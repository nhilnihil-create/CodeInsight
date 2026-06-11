#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
using namespace std;

const long long MOD = 1000000007;




int main() {
  int N;
  cin >> N;
  vector<long long> An(N), Bn(N), Cn(N);
  REP(n,N) cin >> An.at(n);
  REP(n,N) cin >> Bn.at(n);
  REP(n,N) cin >> Cn.at(n);
  sort(An.begin(),An.end());
  sort(Bn.begin(),Bn.end());
  sort(Cn.begin(),Cn.end());

  long long ans = 0;
  long long a, b, c;
  vector<long long>::iterator position;
  long long idx_lower;

  long long k=0,l=0;
  REP(nb,N){
    b = Bn.at(nb);
    position = lower_bound(An.begin(), An.end(), b);
    idx_lower = distance(An.begin(), position);
    k = idx_lower;
    
    position = upper_bound(Cn.begin(), Cn.end(), b);
    idx_lower = distance(Cn.begin(), position);
    l = N-idx_lower;
    ans += k*l;
  }

  cout << ans << endl;
}

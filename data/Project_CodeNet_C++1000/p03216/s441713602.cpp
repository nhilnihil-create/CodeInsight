#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;

int N; 
string S;
vector<ll> d, m, dm;

ll solve(const int k) 
{
  ll ret = 0;
  for(int i = 1; i <= N; i++) {
    if(S[i-1] == 'C') {
      int pos = max(0, i-k);
      ll work = dm[i] - dm[pos];
      ll work2 =  ((m[i]-m[pos]) * d[pos]);
      ret += (work-work2);
      //      cout << i << " " << work << " " << work2 << " " << ret << endl;
    }
  }
  return ret;
}

int main() {
  cin>>N>>S;
  d = vector<ll>(N+1, 0);
  m = vector<ll>(N+1, 0);
  dm = vector<ll>(N+1, 0);
  for(int i = 0; i < N; i++) {
    m[i+1] = m[i];
    d[i+1] = d[i];
    dm[i+1] = dm[i];
    switch (S[i]) {
    case 'D': d[i+1] ++; break;
    case 'M': m[i+1] ++ ; dm[i+1] += d[i]; break;
    }
  }
  int Q; cin>>Q;
  while(--Q >= 0) {
    int k; cin>>k;
    ll ans = solve(k);
    //    cout << "Answer=";
    cout << ans << endl;
  }
  return 0;
}

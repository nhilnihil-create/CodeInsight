#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;
using ll = long long;

ll INF = 1e+18;

int 
main()
{
  int N, K; cin >> N >> K;
  vector<int> m(N + 1);
  int kind = 0;
  rep(i, 1, N + 1){
    int tmp; cin >> tmp;
    m[tmp] += 1;
    if(m[tmp] == 1) ++kind;
  }

  int ans = 0;
  m.erase(remove(m.begin(), m.end(), 0), m.end());
  sort(m.begin(), m.end());
  rep(i, 0, kind - K){
    ans += m[i];
  }

  cout << ans << endl;

}
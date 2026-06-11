#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
  
int main()
{
  int N, K;
  cin >> N >> K;

  vector<int> h(N);
  REP(i, N) cin >> h[i];
  
  sort(ALL(h));

  int MIN = INF;
  REP(i,N-K+1){
    MIN = min(MIN,h.at(i+K-1) - h.at(i));
  }

  cout << MIN << endl;
}
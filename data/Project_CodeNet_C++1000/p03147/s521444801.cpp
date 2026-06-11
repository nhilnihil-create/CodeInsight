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
  int N;
  cin >> N;
  vector<int> vec(N);
  REP(i, N) {
    cin >> vec[i];
  }
  int res = 0;
  while (true) {
    if (*max_element(vec.begin(), vec.end()) == 0) {
      cout << res << endl;
      return 0;
    }
    int i = 0;
    while(i < N && vec[i] == 0) {
      i++;
    }
    res++;
    while(i < N && vec[i] > 0) {
      vec[i]--;
      i++;
    }
  }
  
  return 0;
}
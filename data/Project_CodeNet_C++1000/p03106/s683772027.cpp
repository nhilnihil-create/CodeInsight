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
  int A, B, K;
  vector<int> vec;
  cin >> A >> B >> K;
  for(int i = 1; i <= min(A, B); i++) {
    if ((A % i) == 0 && (B % i) == 0) {
      vec.push_back(i);
    }
  }
  reverse(ALL(vec));
  cout << vec[K-1] << endl;
  
  
  return 0;
}
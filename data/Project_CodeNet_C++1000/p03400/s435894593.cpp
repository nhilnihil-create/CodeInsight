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
  int N, D, X;
  cin >> N >> D >> X;
  vector<int> A(N);
  REP(i, N) cin >> A[i];
  
  D = D - 1;
  int sum = X;
  REP(i,N){
    sum += D/A.at(i) + 1;
  }
  cout << sum << endl;
}
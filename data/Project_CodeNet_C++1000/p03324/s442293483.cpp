#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
int main()
{
  int D, N;
  cin >> D >> N;
  if (N == 100) {
    int v = pow(100, D)*(N+1);
    cout << v << endl;
  } else {
    cout << pow(100, D)*N << endl;
  }
  return 0;
}

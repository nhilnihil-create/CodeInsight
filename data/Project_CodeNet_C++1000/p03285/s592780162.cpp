#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
int main()
{
  int N;
  cin >> N;

  // 4より小さい場合は終わり
  if(N < 4) {
    cout << "No" << endl;
    return 0;
  }

  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= N; j++) {
      if (4 * i + 7 * j == N) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  cout << "No" << endl;
  return 0;
}

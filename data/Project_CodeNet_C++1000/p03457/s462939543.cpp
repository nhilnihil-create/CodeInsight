#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
int main() {
  int N;
  cin >> N;
  int t = 0, x = 0, y = 0;
  REP(i, N) {
    int t1, x1, y1;
    cin >> t1 >> x1 >> y1;
    if((t1-t)>=abs(x1-x)+abs(y1-y)&&(t1-t)%2==(abs(x1-x)+abs(y1-y))%2){

    }else{
      puts("No");
      return 0;
    }
    t = t1, x = x1, y = y1;
  }
  puts("Yes");
}
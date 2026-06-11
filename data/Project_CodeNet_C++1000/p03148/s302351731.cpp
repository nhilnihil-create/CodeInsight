#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <map>
#include <stack>

#define rep(i, N) for (int i = 0; i < (int)N; i++)
using namespace std;
typedef long long ll;
const ll LLINF = 9223372036854775807;
const int INF = pow(2,29);
const int MOD = 1000000007;

struct str{ int t, d; } sushi[(int)pow(10,5)+10];

bool cmp(str a, str b) { return a.d > b.d; }

int main() {
  int N, K; cin >> N >> K;
  rep(i, N) {
    int t, d; cin >> sushi[i].t >> sushi[i].d;
  }
  sort(sushi, sushi+N, cmp);

  stack<int> ss;
  map<int, int> type;
  ll result = 0, tp = 0, sum = 0;
  rep(i,K) { 
    if (!type[sushi[i].t]) { type[sushi[i].t]=1; tp++; }
    else ss.push(sushi[i].d);
    sum += sushi[i].d;
  }
  result = sum + tp*tp;

  for(int i=K; i<N; i++) {
    if (ss.empty()) break;
    if (type[sushi[i].t]) continue;
    type[sushi[i].t] = 1;
    tp++;
    sum -= ss.top(); ss.pop();
    sum += sushi[i].d;
    result = max(result, sum + tp*tp);
    // cout << i << " " << sum << " " << tp << endl;
  }
  // rep(i,N) cout << sushi[i].t << " " << sushi[i].d << endl;
  cout << result << endl;
  return 0;
}
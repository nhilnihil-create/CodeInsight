#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;

int main() {
  ll N, A, B;
  cin >> N >> A >> B;
  ll min_v = 0;
  cout << min(A, B) << " " << max(0LL, A + B - N) << endl;
  return 0;
}
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
struct pos {
  int row;
  int column;
};
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define Sort(a) sort(a.begin(), a.end())
const int INF = 1 << 30;
const ll MOD = 1000000007;
struct Problem {
  ll total;
  ll bonus;
};
vector<Problem> problems;
ll D, G;

int calc(int bit) {
  int count = 0;
  int point = 0;
  for (int i = 0; i < D; i++) {
    if ((bit & (1 << i)) != 0) {
      count += problems[i].total;
      point += problems[i].bonus + (((i + 1) * 100) * problems[i].total);
    }
  }

  if (point >= G) return count;

  for (int i = D - 1; i >= 0; i--) {
    if ((bit & (1 << i)) == 0) {
      for (int total = 1; total < problems[i].total; total++) {
        count += 1;
        point += ((i + 1) * 100);

        if (point >= G) return count;
      }
    }
  }

  return INF;
}

int main(void) {
  cin >> D >> G;
  problems.resize(D);
  rep(i, D) { cin >> problems[i].total >> problems[i].bonus; }

  int minVal = INF;
  for (int bit = 0; bit < (1 << 10); bit++) {
    minVal = min(minVal, calc(bit));
  }

  cout << minVal << endl;

  return 0;
}
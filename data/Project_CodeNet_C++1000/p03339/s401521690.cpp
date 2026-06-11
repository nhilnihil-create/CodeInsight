#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int, int> p;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define reps(i, n) for(int i = 1; i <= (int)(n); i++)
#define rrep(i, n) for(int i = ((int)(n)-1); i >= 0; i--)
#define srep(i, from, to) for(int i = from; i < (int)(to); i++)
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
template <class T> bool chmax(T &a, const T &b) {
  if(a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T> bool chmin(T &a, const T &b) {
  if(b < a) {
    a = b;
    return 1;
  }
  return 0;
}

int main() {
  int n;
  string s;
  cin >> n >> s;
  vector<int> sumw = vector<int>(n + 1);
  vector<int> sume = vector<int>(n + 1);
  rep(i, n) {
    sumw[i + 1] = sumw[i];
    if(s[i] == 'W') sumw[i + 1]++;
    sume[i + 1] = sume[i];
    if(s[i] == 'E') sume[i + 1]++;
  }

  // E ->
  // W <-

  int ans = INF;
  rep(i, n) {
    int now = 0;
    now += sumw[i];
    now += sume[n] - sume[i + 1];
    chmin(ans, now);
  }
  cout << ans << endl;

  return 0;
}

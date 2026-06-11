#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = (0); i < (n); ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define DEBUG(val) cout << #val << " : " << val << endl
#define MOD 1000000007

int h, w;
void print(vector<string> &data) {
  REP(i, h) {
    REP(j, w) { cout << data[i][j]; }
    cout << endl;
  }
}

int main() {
  ll ans = 0;
  ll cnt = 0;
  vector<string> data;
  cin >> h >> w;
  REP(i, h) {
    string s;
    cin >> s;
    data.push_back(s);
  }
  queue<pair<int, int>> candidate;
  REP(i, h) {
    REP(j, w) {
      if (data[i][j] == '#') {
        candidate.push(make_pair(i, j));
        cnt++;
      }
    }
  }
  while (true && cnt != h * w) {
    ans++;
    queue<pair<int, int>> tmp;
    while (!candidate.empty()) {
      pair<int, int> p = candidate.front();
      candidate.pop();
      if (p.first - 1 >= 0 && data[p.first - 1][p.second] == '.') {
        data[p.first - 1][p.second] = '#';
        tmp.push(make_pair(p.first - 1, p.second));
        cnt++;
      }
      if (p.first + 1 < h && data[p.first + 1][p.second] == '.') {
        data[p.first + 1][p.second] = '#';
        tmp.push(make_pair(p.first + 1, p.second));
        cnt++;
      }
      if (p.second - 1 >= 0 && data[p.first][p.second - 1] == '.') {
        data[p.first][p.second - 1] = '#';
        tmp.push(make_pair(p.first, p.second - 1));
        cnt++;
      }
      if (p.second + 1 < w && data[p.first][p.second + 1] == '.') {
        data[p.first][p.second + 1] = '#';
        tmp.push(make_pair(p.first, p.second + 1));
        cnt++;
      }
    }
    candidate = tmp;
  }
  cout << ans << endl;
}
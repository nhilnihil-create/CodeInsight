#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).rbegin(), (x).rend()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void solve() {
  int n;
  cin >> n;
  map<string, vector<pii>> mp;
  rep(i,n) {
    string s;
    int p;
    cin >> s >> p;
    mp[s].push_back(pii(p, i+1));
  }
  for (auto pr: mp) {
    sort(ALL(pr.second));
    for (auto i: pr.second) {
      cout << i.second << endl;
    }
  }
}

int main() {
  solve();
  return 0;
}
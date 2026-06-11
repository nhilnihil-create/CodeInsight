#include <bits/stdc++.h>
#define REP(i, n) for (long long i = 0; i < (long long)n; i++)
//#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
using Pi = pair<int, int>;
using Pl = pair<ll, ll>;
using Vl = vector<ll>;
using vi = vector<int>;
using Graph = vector<vi>;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  // std::cout << std::fixed << std::setprecision(15); //"for float-base
  // problem"
  int N, K;
  map<int, int> nums;
  cin >> N >> K;
  REP(i, N) {
    int num;
    cin >> num;
    nums[num]++;
  }
  vi cnt;
  for (auto a : nums) {
    cnt.push_back(a.second);
  }
  sort(cnt.begin(), cnt.end());
  int ans = 0;
  REP(i, cnt.size() - K) { ans += cnt.at(i); }
  cout << ans << endl;
}
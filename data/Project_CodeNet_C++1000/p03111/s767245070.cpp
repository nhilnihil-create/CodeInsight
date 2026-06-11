#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
#include<deque>
using namespace std;

using ll = long long;
const int INF = 1001001001;
const ll LLINF = 1001001001001001001;

#define rep(i,n) for (int i = 0; i < (n); ++i)

int main()
{
  int a, b, c;
  int n;
  cin >> n >> a >> b >> c;
  vector<int> m;
  rep(i,n) {
    int tmp;
    cin >> tmp;
    m.push_back(tmp);
  }
  int result = INF;
  rep(i,pow(4,m.size())) {
    int ma = 0, mb = 0, mc= 0;
    int maCount = 0, mbCount = 0, mcCount = 0;
    rep(j,m.size()) {
      int type = (i >> (j * 2)) & 3;
      if (type == 0) {
        /*pass through*/
      } else if (type == 1) {
        ma += m[j];
        maCount++;
      } else if (type == 2) {
        mb += m[j];
        mbCount++;
      } else {
        mc += m[j];
        mcCount++;
      }
    }
    if (ma == 0 || mb == 0 || mc == 0) continue;
    int totalCost = (--maCount + --mbCount + --mcCount) * 10 + abs(ma-a) + abs(mb-b) + abs(mc-c);
    result = min(result, totalCost);
  }
  cout << result << endl;
}

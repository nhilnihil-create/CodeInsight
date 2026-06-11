#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const ll INF = (ll)5e15;

int main() {
  int n;
  cin >> n;
  P now = P(0,0);
  int time = 0;
  rep(i,n) {
    int t,x,y;
    cin >> t >> x >> y;
    int dist = abs(x-now.first) + abs(y-now.second);
    if(dist > (t-time)) {
      cout << "No" << endl;
      return 0;
    }
    int res = abs((t-time) - dist);
    if(res%2 == 0) {
      time = t;
      now = P(x,y);
    } else {
      cout << "No" << endl;
        return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <chrono>
#include <random>
#include <functional>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
typedef long long ll;

using ipair = pair<int, int>;

ll INF = 1e16+7;
ll mod = 1e9+7;

bool operator>(const ipair a,const ipair b){return a.first > b.first;}

int main(){
  ll N, H;
  cin >> N >> H;
  int blade = -1;
  priority_queue<int> q;
  rep(i, N){
    int a, b;
    cin >> a >> b;
    blade = max(blade, a);
    q.push(b);
  }

  int ans = 0;
  while(!q.empty() && q.top() >= blade && H > 0){
    H -= q.top(); q.pop();
    ans++;
  }

  H = max(0LL, H);

  ans += (int)ceil((1.0*H) / (1.0*blade));

  cout << ans << endl;

  return 0;
}

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


const double PI=3.14159265358979323846;

int main(){
  int N, K;
  cin >> N >> K;

  vector<int> candle(N);
  rep(i, N) cin >> candle[i];

  int ans = 1e9;

  rep(l, N){
    int r = l + (K-1);
    if(r > N-1){
      break;
    }
    ans = min(ans, abs(candle[l]) + (candle[r] - candle[l]));
    ans = min(ans, abs(candle[r]) + (candle[r] - candle[l]));
  }

  cout << ans << endl;

  return 0;
}

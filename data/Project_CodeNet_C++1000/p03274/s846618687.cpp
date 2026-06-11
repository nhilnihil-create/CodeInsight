#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
int main(){
  int n,k;
  cin >> n >> k;
  vector<int> candle(n);
  for(int i = 0;i < n;i++)cin >> candle[i];
  int res = 0;
  res = INT_MAX;
  for(int i = 0;i <= n - k;i++){
    res = min(res,min(abs(candle[i]),abs(candle[i + k - 1])) + abs(candle[i + k - 1] - candle[i]));
    //res = min(res,abs(candle[i + k - 1] + abs(candle[i + k - 1] - candle[i])));
  }
  cout << res << endl;
}
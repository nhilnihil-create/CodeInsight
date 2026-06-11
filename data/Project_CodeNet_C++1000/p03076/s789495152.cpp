#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define VB vector<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
#define ALL(v) (v).begin(), (v).end()

int main() {
  vector<int> dish_time(5);
  int sum_time = 0;
  for (int i = 0; i < 5; ++i) {
    cin >> dish_time.at(i);
    sum_time += (dish_time.at(i) + 9) / 10 * 10;
  }
 
  int min_time = 0;
  for (int i = 0; i < 5; ++i) {
    min_time = max(min_time, ((dish_time.at(i) + 9) / 10 * 10) - dish_time.at(i));
  }
 
  cout << sum_time - min_time << endl;
  return 0;
}
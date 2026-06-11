#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

int main(){
  int N, H, W;
  cin >> N >> H >> W;
  pair<int, int> p[N];
  for(int i = 0; i < N; i++) cin >> p[i].first >> p[i].second;

  int ans = 0;
  for(int i = 0; i < N; i++){
    if(p[i].first >= H && p[i].second >= W) ans++;
  }

  cout << ans << endl;
  return 0;
}

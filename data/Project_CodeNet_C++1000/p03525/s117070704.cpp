#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N;
  cin >> N;
  int D[N];
  for (int i = 0; i < N; i++) cin >> D[i];
  int num[13];
  for (int i = 0; i < 13; i++) {
    num[i] = 0;
  }
  for (int i = 0; i < N; i++) {
    num[D[i]]++;
  }
  vector<int> one;
  vector<int> two;
  vector<int> three;
  if (num[0] != 0) {
    cout << 0 << endl;
    return 0;
  }

  for (int i = 0; i <= 12; i++) {
    if (num[i] == 1) {
      one.push_back(i);
    } else if (num[i] == 2) {
      two.push_back(i);
    } else if (num[i] >= 3) {
      three.push_back(i);
    }
  }
  if (!three.empty()) {
    cout << 0 << endl;
    return 0;
  }
  int on = (int)one.size();
  int ans = 0;
  for (int bit = 0; bit < (1 << on); bit++) {
    vector<int> time;
    time.clear();
    for (int i = 0; i < (int)two.size(); i++) {
      time.push_back(two[i]);
      time.push_back(24-two[i]);
    }
    time.push_back(0);
    for (int i = 0; i < on; i++) {
      if ((1 << i) & bit) {
        time.push_back(one[i]);
      } else {
        time.push_back(24-one[i]);
      }
    }
    sort(time.begin(),time.end());
    int res = 99999;
    for (int i = 0; i < (int)time.size(); i++) {
      for (int j = i + 1; j < (int)time.size(); j++) {
        int a = min(time[i],time[j]);
        int b = max(time[i],time[j]);
        res = min(res,b-a);
        res = min(res,24+a-b);
      }
    }
    ans = max(ans,res);
  }
  cout << ans << endl;
  return 0; 
}
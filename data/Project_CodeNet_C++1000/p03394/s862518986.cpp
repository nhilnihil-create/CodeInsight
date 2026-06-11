#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N;
  cin >> N;
  if (N == 3) {
    cout << "2 5 63" << endl;
    return 0;
  }
  if (N == 4) {
    cout << "2 5 20 63" << endl;
    return 0;
  }
  vector<int> seq = {2,3,4,9};
  vector<int> ans;
  if (N <= 100) {
    ans = seq;
    for (int i = 6; i < 1000000; i+=6) {
      ans.push_back(i);
      if ((int)ans.size() == N) {
        break;
      }
    }
  } else {
    int newN = (N+7)/8;
    vector<int> seq2 = {2,3,4,6,8,9,10,12};
    for (int i = 0; i < newN; i++) {
      for (int j = 0; j < 8; j++) {
        ans.push_back((i * 12) + seq2[j]);
      }
    }
    for (int i = 0; i < (int)ans.size(); i++) {
      if (ans[i] % 6 == 0) {
        ans.erase(ans.begin()+i);
      }
      if ((int)ans.size() == N) {
        break;
      }
    }
  }

  for (int i = 0; i < (int)ans.size(); i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}
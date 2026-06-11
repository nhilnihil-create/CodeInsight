#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;

int main() {
  int N;
  cin >> N;
  string res[N];
  cout << 0 << endl;
  string s;
  cin >> s;
  int left = -1;
  int right = -1;
  if (s == "Vacant") return 0;
  cout << N - 1 << endl;
  string t;
  cin >> t;
  if (t == "Vacant") return 0;
  res[0] = s;
  res[N - 1] = t;
  left = 0;
  right = N - 1;
  int cnt = 2;
  while (0 == 0) {
    cnt++;
    int mid = (left + right) / 2;
    cout << mid << endl;
    string str;
    cin >> str;
    res[mid] = str;
    if (str == "Vacant") return 0;
    int lr = mid - left + 1;
    int rr = right - mid + 1;
    if ((lr % 2 == 1 && res[mid] != res[left]) || lr % 2 == 0 && res[mid] == res[left]) {
      right = mid;
    } else {
      left = mid;
    }
    if (cnt == 20) {
      return 0;
    }
  }
  return 0;
}
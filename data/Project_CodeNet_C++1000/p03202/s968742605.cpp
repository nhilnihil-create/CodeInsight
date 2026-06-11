#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 2e5 + 5;

int n;
int arr [MAX_N];

int can (int k) {
  if (k == 0 || k == 1) return false;
 
  vector<pair<int, int>> cur; // all the nonzero elements
  for (int i = 1; i < n; i++) {
    if (arr[i] <= arr[i - 1]) {
      while (!cur.empty() && cur.back().first >= arr[i]) cur.pop_back();

      int t = arr[i] - 1;
      while (true) {
        if (t < 0) return false;
        
        if (!cur.empty() && cur.back().first == t) {
          cur.back().second++;
          if (cur.back().second == k) {
            cur.pop_back();
            t--;
          } else {
            break;
          }
        } else {
          cur.push_back(make_pair(t, 1));
          break;
        }
      }
    }
  }
  
  return true;
}

int main () {
  ios::sync_with_stdio(false);

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int flag = 1;
  for (int i = 1; i < n; i++) {
    if (arr[i] <= arr[i - 1]) {
      flag = 0;
    }
  }

  if (flag) {
    cout << 1 << endl;
    return 0;
  }
  
  int ans = 0;
  for (int k = 1 << 20; k != 0; k /= 2) {
    if (!can(ans + k)) {
      ans += k;
    }
  }

  cout << ans + 1 << endl;
}

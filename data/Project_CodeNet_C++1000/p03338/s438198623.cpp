#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;
  vector<int> vec(26, 0);
  for (int i = 0; i < n; ++i)
    ++vec[s[i] - 'a'];

  int cnt_max = 0;
  int cnt = 0;
  vector<int> selected(26, false);
  for (int i = 0; i < n; ++i) {
    char c = s[i] - 'a';
    if (1 < vec[c] && selected[c] == false) {
      ++cnt;
      selected[c] = true;
    }
    if (vec[c] == 1 && selected[c] == true)
      --cnt;
    --vec[c];
    cnt_max = max(cnt_max, cnt);
  }

  cout << cnt_max << endl;
}

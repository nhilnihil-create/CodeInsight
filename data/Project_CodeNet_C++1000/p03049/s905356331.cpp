#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> vec(n);
  int cnt1 = 0;
  int cnt2 = 0;
  int cnt3 = 0;
  int cnt4 = 0;
  for (auto &v : vec) {
    cin >> v;
    int tmp = static_cast<int>(v.size());
    for (int i = 0; i < tmp - 1; ++i)
      cnt1 += v.substr(i, 2) == "AB";
    cnt2 += v[0] == 'B';
    cnt3 += v[tmp-1] == 'A';
    cnt4 += v[0] == 'B' && v[tmp-1] == 'A';
  }

  if (cnt2 == cnt4 && cnt3 == cnt4)
    cout << max(cnt4 - 1, 0) + cnt1 << endl;
  else
    cout << min(cnt2, cnt3) + cnt1 << endl;
}



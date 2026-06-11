#include <bits/stdc++.h>
#include <vector>

#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

int main(void)
{
  int n;
  cin >> n;
  vector<int> odd;
  for (int i = 1; i <= n; i += 2) {
    odd.push_back(i);
  }

  int res = 0;
  for (int num : odd) {
    int count = 0;
    for (int i = 1; i <= num; ++i) {
      if (num % i == 0) ++count;
    }
    if (count == 8) ++res;
  }
  cout << res << endl;
}
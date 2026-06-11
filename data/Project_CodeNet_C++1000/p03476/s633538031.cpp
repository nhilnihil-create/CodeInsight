#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
  int max_n = 100000;
  vector<bool> is_prime(max_n + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i < is_prime.size(); i++) {
    if (!is_prime[i]) {
      continue;
    }

    for (int j = i * 2; j < is_prime.size(); j += i) {
      is_prime[j] = false;
    }
  }

  vector<int> cnts(max_n + 1, 0);
  for (int i = 1; i < cnts.size(); ++i) {
    if (is_prime[i] && is_prime[(i + 1)/2]) {
      cnts[i] = cnts[i - 1] + 1;
    } else {
      cnts[i] = cnts[i - 1];
    }
  }

  int q;
  cin >> q;

  vector<int> ans;
  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;
    ans.push_back(cnts[r] - cnts[l - 1]);
  }

  for (int i = 0; i < ans.size(); ++i) {
    cout << ans[i] << '\n';
  }
  return 0;
}
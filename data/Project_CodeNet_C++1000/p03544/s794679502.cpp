#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N;
  cin >> N;

  int64_t l1=2, l2=1;

  rep(i, N)
  {
    l1 += l2;
    swap(l1, l2);
  }

  cout << l1;

}

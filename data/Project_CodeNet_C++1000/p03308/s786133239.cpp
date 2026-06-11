#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N;
  int min_num = pow(10, 9);
  int max_num = 0;
  cin >> N;

  rep(i, N) {
    int a;
    cin >> a;
    min_num = min(min_num, a);
    max_num = max(max_num, a);
  }

  cout << abs(max_num - min_num) << endl;

  return 0;
}
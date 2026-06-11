#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  vector<int> maximum(5);
  vector<int> minimum(5);
  rep(i, 5) {
    cin >> minimum[i];
    if(minimum[i] % 10 == 0) maximum[i] = minimum[i];
    else maximum[i] =((minimum[i] / 10) + 1)*10;
  }
  int cmp = -1;
  int sum = 0;
  rep(i, 5) {
    sum += maximum[i];
    int tmp = abs(maximum[i] - minimum[i]);
    if(tmp >cmp) {
      cmp = tmp;
    }
  }
  int ans = sum - cmp;
  cout << ans << endl;
}
  
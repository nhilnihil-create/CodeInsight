#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
#define rep(i,n) for (int i = 0; i < (n); i++)

int divisor(int n) {
  vector<int> ret;
  for(int i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  return ret.size();
}

int main() {
  int n;
  cin >> n;
  int cnt = 0;
  for (int i = 1; i <= n; i += 2) {
    int x = divisor(i);
    if (x == 8) cnt++;
  }
  cout << cnt << endl;
}

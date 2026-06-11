#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
  long long a,b,c,k;
  cin >> a >> b >> c >> k;
  bool flag = false;
  long long n = k%2==0?a-b:b-a;
  cout << n << endl;
}

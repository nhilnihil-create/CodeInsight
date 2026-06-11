#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  int N, A, B;
  cin >> N >> A >> B;
  
  cout << min(A, B) << " " << abs(min(0LL, N-A-B)) << endl;
  
}
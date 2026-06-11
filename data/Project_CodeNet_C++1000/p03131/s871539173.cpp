#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG

signed main() {
  int K, A, B; cin >> K >> A >> B;
  
  if(A >= B-2 || A >= K) cout << K+1 << endl;
  else {
    int a = A;
    K -= A-1;
    a -= A;
    K--;
    a += B;
    K--;
    cout << a+(K/2)*(B-A)+(K%2) << endl;
  }

}
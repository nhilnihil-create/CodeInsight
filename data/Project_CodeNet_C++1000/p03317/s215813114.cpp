#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}
const int MOD = 1000000007;

int N, K;
vector<int> A;

int main() {
    while (cin >> N >> K) {
      A.resize(N);
      for (int i = 0; i < N; ++i) cin >> A[i];
      int res = 0;
      int right = 0;
      while (true) {
        if (res == 0) right += K;
        else right += K-1;
        ++res;

        if (right >= N) break;
      }
      cout << res << endl;
    }
}



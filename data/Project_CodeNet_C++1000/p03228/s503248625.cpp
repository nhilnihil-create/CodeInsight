#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
#define ALL(v) v.begin(), v.end()
#define vmax(v) *max_element(ALL(v))
#define vmin(v) *min_element(ALL(v))
#define chmax(x, a) x = max(x, a)
#define chmin(x, a) x = min(x, a)

int main() {
    int A, B, K; cin >> A >> B >> K;
  	rep(i, K) {
      if (i%2==0) {
        B += A/2;
        A/=2;
      }
      else {
        A += B/2;
        B/=2;
      }  
    }
  cout << A << " " << B << endl;
}

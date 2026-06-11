#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

const int mod = 1e9+7;
void add_self(int &a, int b) {a+=b; if(a>=mod) a-=mod;}
void sub_self(int &a, int b) {a-=b; if(a<0) a+=mod;}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
 
  // dp[i] : no. of ways s.t. we used i candies
  vector<int> dp(k+1);
  dp[0] = 1;
  for(int j=0; j<n; j++) {
    int upto;
    cin >> upto;
    vector<int> fake(k+1);
    for(int used=k; used>=0; used--) {
      int L = used + 1;
      int R = used + min(upto, k-used);
      if(L <= R) {
        add_self(fake[L], dp[used]);
        if(R+1 <= k) {
          sub_self(fake[R+1], dp[used]);
        }
      }
    }
    int prefix_sum = 0;
    for(int i=0; i<=k; i++) {
      add_self(prefix_sum, fake[i]);
      add_self(dp[i],  prefix_sum);
    }
  }
  cout << dp[k] << '\n';

  return 0;
}

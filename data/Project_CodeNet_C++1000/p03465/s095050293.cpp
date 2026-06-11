#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const int INT_INF = 2147483647;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef pair<int,int> P;

int main() {
  int n;
  cin >> n;
  int a[n];
  rep(i,n)cin >> a[i];

  // DP の遷移を bitset に落とし込む
  bitset<4000005> dp(1);
  rep(i,n) dp |= (dp << a[i]);

  // 答えを出力
  int sum=0;
  rep(i,n)sum+=a[i];
  for(int i=(sum+1)/2;i<=sum;i++){
    if(dp[i]==1){
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}

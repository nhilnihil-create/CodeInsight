#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m1(x) memset(x,-1,sizeof(x))
const ll INF = 1e18 + 1;
const ll MOD = 1e9 + 7;
const double PI = 3.141592653589793;


int main(){
  int n, k;
  cin >> n >> k;
  int v[50];
  rep(i, n) cin >> v[i];
  ll ans = -INF;
    
  for(int i = 1; i <= k; i++){
    for(int j = 0; j <= i && j <= n; j++){
      //左からj個、右からi-j個とって、k-i個まで捨てる
      vector<int> jewelry;
      for(int l = 0; l < j; l++){
        jewelry.push_back(v[l]);
      }
      for(int l = 0; l < i-j && l < n - j; l++){
        jewelry.push_back(v[n-l-1]);
      }
      sort(all(jewelry));
      ll tmp = 0;
      for(int x: jewelry) tmp += x;
      for(int l = 0; l < k-i; l++){
        tmp = max(tmp, tmp - jewelry[l]);
        }
      ans = max(tmp, ans);
    }
    //cout << ans << endl;
  }
  cout << max(ll(0), ans) <<endl;
}
    
    
    
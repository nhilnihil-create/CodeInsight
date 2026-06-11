#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
#define all(x) (x).begin(),(x).end()

int main(){
  int n, k;
  cin >> n >> k;
  vector<int> pos(n);
  for(int i=0; i<n; i++)  cin >> pos[i];
  sort(all(pos));

  int ans = 1000000000;
  for(int i=0; i<n; i++){
    if(i+k>n) break;
    int left = abs(pos[i]), right = abs(pos[i+k-1]);
    if(pos[i] > 0 && pos[i+k-1] > 0)  
      ans = min(ans, right);
    else if (pos[i] < 0 && pos[i+k-1] < 0)  
      ans = min(ans, left);
    else {
      int num;
      if(left < right) num = left * 2 + right;
      else num = left + right * 2;
      ans = min(ans, num);
    }
  }
  
  cout << ans << ln;
}
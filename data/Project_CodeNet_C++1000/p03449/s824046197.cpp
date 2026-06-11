#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
const int MOD = 1e9+7;
using ll = long long;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ALL(x) x.begin(), x.end()
int main() {
  int a,ans = 0,sum=0,tmp;
  cin >> a;
  int up[a],down[a];
  rep(i,a){
    cin >> up[i];
    sum += up[i];
  }
  rep(i,a){
    cin >> down[i];
    sum += down[i];  
  }
  for(int i = 1;i<a;i++){
      ans += up[i];
  }
   tmp = ans;
  for(int i = 1;i<a;i++){
      ans = ans-up[i]+down[i-1];
      tmp = min(ans,tmp);
  }
  cout << sum - tmp << endl;
}
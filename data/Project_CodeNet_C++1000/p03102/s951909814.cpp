#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const int MOD = 1e9+7;
using ll = long long;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ALL(x) x.begin(), x.end()
int main() {
  int a,b,c,tmp,sum,ans=0;
  cin >> a >> b >> c;
  int N[b];
  rep(i,b){
    cin >> N[i];
  }
  rep(i,a){
    sum = c;
    rep(i,b){
      cin >> tmp;
      sum += tmp * N[i];
    }
    if(sum>0)ans++;
  }
  cout << ans;
}
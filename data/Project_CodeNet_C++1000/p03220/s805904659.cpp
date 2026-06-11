#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
 
int main(){
  int n, t, a, ans;
  double temp=1000;
  cin >> n >> t >> a;
  rep(i, n){
    int j;
    cin >> j;
    double x = t - j * 0.006;
    if(temp > abs(a - x)){
      temp = abs(a - x);
      ans = i + 1;
    }
  }
  cout << ans << endl;
}
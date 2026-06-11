#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int a, b;
  cin >> a >> b;
  int ans = 0;
  rep(i,2){
    if(a>=b){
      ans += a;
      a--;
    }
    else{
      ans += b;
      b--;
    }
  }
  cout << ans << endl;
}

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
using namespace std;
using ll = long long;
using P = pair<int, int>;
 
int main() {
  int n;
  cin >> n;
  double ans = 0;
  rep(i,n){
    double x;
    cin >> x;
    string u;
    cin >> u;
    if(u == "JPY"){
      ans += x;
    }
    else{
      ans += x * 380000.0;
    }
  }
  cout << ans << endl;
}
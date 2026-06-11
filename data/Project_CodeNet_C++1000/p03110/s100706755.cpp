#include <iostream>
#include <string>
#include <cmath>
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, s, n) for(int i = s; i < n; i++)
using namespace std;

int main(){
  int n;
  cin >> n;
  double ans = 0.0;
  rep(i, n){
    double x;
    string u;
    cin >> x >> u;
    if (u == "JPY") ans += x;
    else ans += x * 380000.0;
  }
  cout << ans << endl;
  return 0;
}
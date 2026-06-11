#include <iostream>
#include <string>
#include <cmath>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
  string s;
  cin >> s;
  int n = s.size();
  int ans = 1000;
  rep(i, n-2){
    int num;
    num = (s[i] - '0') * 100 + (s[i+1] - '0') * 10 + (s[i+2] - '0');
    ans = min(ans, abs(num-753));
  }
  cout << ans << endl;
}
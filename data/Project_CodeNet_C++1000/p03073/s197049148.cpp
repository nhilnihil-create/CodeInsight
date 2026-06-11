#include <iostream>
#include <string>
#include <cmath>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
  string s;
  cin >> s;
  int n = s.size();
  int sum1 = 0, sum2 = 0;
  rep(i, n){
    if (i % 2 == 0 && s[i] == '1') sum1++;
    else if (i % 2 == 1 && s[i] == '0') sum1++;
    if (i % 2 == 0 && s[i] == '0') sum2++;
    else if (i % 2 == 1 && s[i] == '1') sum2++;
  }
  cout << min(sum1, sum2) << endl;
  
  return 0;
}
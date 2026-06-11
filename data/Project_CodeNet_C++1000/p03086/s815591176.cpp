#include <bits/stdc++.h>
const double PI = acos(-1);
#define rep(i, n) for (int i = 0; i < (int)(n); i++ )
using namespace std;
int findSumOfDigits(int n) {
  int sum = 0;
  while (n > 0) { // n が 0 になるまで
    sum += n % 10;
    n /= 10;
  }
  return sum;
}
int main(){
  string s;
  cin >> s;
  int n = s.size() ;
  vector<int> num(n);
  rep(i,n){
    if(s.at(i) != 'A' && s.at(i) != 'C'&& s.at(i) != 'G'&& s.at(i) != 'T' ){
      num.at(i)++;
    }
  }
  int ans = 0, ansmax = 0;
  rep(i,n){
    if(num.at(i) == 0){
      ans++;
      if(i == n-1){
        if(ans > ansmax) ansmax = ans;
      }
    }
    else if(num.at(i) == 1) {
      if(ans > ansmax){
        ansmax = ans;
      }
      ans = 0;
    }
  }
  cout << ansmax << endl;
}
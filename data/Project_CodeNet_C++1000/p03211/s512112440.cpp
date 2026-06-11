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
int fn(long long x, long long y, long long z){
  return x*x + y*y + z*z + x*y + y*z + z*x;
}
int main(){
  string s;
  cin >> s;
  vector<int> n(s.size());
  rep(i,s.size()){
    if(s.at(i) == '1') n.at(i) = 1;
    else if(s.at(i) == '2') n.at(i) = 2;
    else if(s.at(i) == '3') n.at(i) = 3;
    else if(s.at(i) == '4') n.at(i) = 4;
    else if(s.at(i) == '5') n.at(i) = 5;
    else if(s.at(i) == '6') n.at(i) = 6;
    else if(s.at(i) == '7') n.at(i) = 7;
    else if(s.at(i) == '8') n.at(i) = 8;
    else if(s.at(i) == '9') n.at(i) = 9;
  }
  int num;
  if(n.at(0)*100 + n.at(1)*10 + n.at(2) >= 753 ){
    num = n.at(0)*100 + n.at(1)*10 + n.at(2) - 753;
  }
  else num = 753 - (n.at(0)*100 + n.at(1)*10 + n.at(2)); 
  int ans = num;
  rep(i,s.size()-2){
    if(n.at(i)*100 + n.at(i+1)*10 + n.at(i+2) >= 753 ){
    num = n.at(i)*100 + n.at(i+1)*10 + n.at(i+2) - 753;
    }
    else num = 753 - (n.at(i)*100 + n.at(i+1)*10 + n.at(i+2)); 
    if(num < ans  ) ans = num;
  }
  cout << ans << endl;
}
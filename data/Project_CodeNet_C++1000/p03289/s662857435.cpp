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
  if(s.at(0) == 'A' && s.at(s.size()-1) != 'C'){
    int num = 0;
    int B = 0;
    int a;
    for(int i = 2; i < s.size()-1;i++){
      if(s.at(i) == 'C') num++;
    }
    for(int i = 1; i < s.size(); i++){
      a = s.at(i);
      if(a >= 65 && a <= 90  ) ++B;
    }
    if(num == 1 && B == 1) cout << "AC" << endl;
    else cout << "WA" << endl;
  }
  else cout << "WA" << endl;
}
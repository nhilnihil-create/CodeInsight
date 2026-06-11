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
  string s, t;
  cin >> s >> t;
  int n = s.size();
  string s2 = s;
  char begin ,end;
  rep(i,s.size()){
    if( s == t){
      cout << "Yes" << endl;
      break;
    }
    s2.at(0) = s.at(s.size()-1);
    for(int i = 1;i<n;i++){
      s2.at(i) = s.at(i-1);
    }
    s = s2;
    if(i == s.size()-1){
      if(s == t) cout << "Yes" << endl;
      else cout << "No" << endl;
    }
  }
}
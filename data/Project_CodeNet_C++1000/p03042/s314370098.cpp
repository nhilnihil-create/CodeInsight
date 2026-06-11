#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  string s;
  cin >> s;
  int a, b;
  a = (s[0] - '0')*10 + s[1] - '0';
  b = (s[2] - '0')*10 + s[3] - '0';
  if(1 <= a && a <= 12){
    if(1 <= b && b <= 12){
      cout << "AMBIGUOUS";
    }
    else{
      cout << "MMYY";
    }
  }
  else{
    if(1 <= b && b <= 12){
      cout << "YYMM";
    }
    else{
      cout << "NA";
    }
  }
    
    
  return 0;
}



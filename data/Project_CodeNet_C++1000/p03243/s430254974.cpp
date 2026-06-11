#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int N;
  cin >> N;

  string digit;
  bool same = true;
  for (int i = N; i < 1000; i++)
  {
    digit = to_string(i);
    same = true;
    if (digit.at(0) != digit.at(1) || digit.at(1) != digit.at(2)){
      same = false;
    }
    if (same){
      cout << i << endl;
      break;
    }
  }
  
}
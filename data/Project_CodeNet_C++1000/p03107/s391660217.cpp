#include <bits/stdc++.h>
using namespace std;
int main(){
  string S;
  int a = 0,b = 0;
  cin >> S;
  for(int i = 0;i < S.size(); i++){
    if(S.at(i) == '0')
      a++;
    else
      b++;
  }
  int kaisuu = min(a,b);
  cout << kaisuu * 2 << endl;
}


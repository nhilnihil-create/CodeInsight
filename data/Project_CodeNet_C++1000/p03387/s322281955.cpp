#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>

using namespace std;

int main(){
  int A, B, C;
  cin >> A >> B >> C;

  int X = max({A, B, C});
  int min = (3*X - (A+B+C))/2;
  if((3*X)%2 - (A+B+C)%2 == 0) {
    cout << min << endl;
  }else{
    cout << min+2 << endl;
  }

  return 0;
}
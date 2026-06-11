#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
 
int main() {
  int a,b,c;
  cin >> a >> b >> c;
  string result;
  
  if(b == a && c == b) {
    result = "Yes";
  }
  else{
    result = "No";
  }

  cout << result << endl;

}
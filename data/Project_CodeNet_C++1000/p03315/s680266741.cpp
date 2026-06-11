#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

int main(){
  string s;
  cin >> s;
  
  int n = 0;
  for (int i=0 ; i<4 ; i++){
    if (s.at(i) == '+')
      n++;
    else
      n--;
  }
  
  cout << n << endl;
}
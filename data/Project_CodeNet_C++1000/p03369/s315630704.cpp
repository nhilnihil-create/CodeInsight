#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  int ex = 0;
  for(int i = 0; i < 3; i++){
    if(s[i] == 'o') ex++;
  }
  cout << 700 + 100 * ex << endl;
  return 0;
}
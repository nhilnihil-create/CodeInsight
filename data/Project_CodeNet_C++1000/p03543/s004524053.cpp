#include <bits/stdc++.h>
using namespace std;

int main(){
  string n;
  cin >> n;
  
  int a = 0, ans = 0;
  for (int i=0 ; i<3 ; i++){
    if (a == 2){
      ans = 1;
      break;
    }
    if (n.at(i) == n.at(i+1))
      a++;
    else
      a = 0;
  }
  if (a == 2)
    ans = 1;
  
  if (ans == 1)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
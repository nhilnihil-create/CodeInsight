#include <bits/stdc++.h>
using namespace std;
int main(){
  int d; cin >> d;
  string res;
  switch(d){
    case 22:
      res = "Christmas Eve Eve Eve";
      break;
    case 23:
      res = "Christmas Eve Eve";
      break;
    case 24:
      res = "Christmas Eve";
      break;
    case 25:
      res = "Christmas";
      break;
  }
  cout << res << endl;
  return 0;
}
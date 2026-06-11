#include <bits/stdc++.h>
using namespace std;

int main(){
  int D;
  cin >> D;
  string s="Christmas";
  string e=" Eve";
  for(int i=0;i<abs(D-25);i++){
    s+=e;
  }
  cout << s << endl;
  return 0;
}

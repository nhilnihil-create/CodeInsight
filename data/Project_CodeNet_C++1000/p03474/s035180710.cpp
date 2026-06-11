#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,a=0;
  string S;
  cin >> A >> B >>S;
  for (int i=0;i<A+B+1;i++){
  if (i==A && S.at(i)!='-'){
  a++;
  }
  else if (i!=A && S.at(i)=='-'){
  a++;
  }
  }

  if (a>0){
  cout << "No" << endl;
  }
  else {
  cout << "Yes" << endl;
  }
  
}
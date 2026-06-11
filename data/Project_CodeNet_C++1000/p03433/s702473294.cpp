#include <bits/stdc++.h>
using namespace std;

int main(){
  int a, b;
  cin >> a >> b;
  while (a >= 500){
    a = a - 500;
  }
  if (a <= b){
    cout << "Yes";
  }
  else {
    cout << "No";
  }
}


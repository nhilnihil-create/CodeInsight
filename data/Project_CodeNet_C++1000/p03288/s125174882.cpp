#include <bits/stdc++.h>
using namespace std;

int main() {
  int a;
  cin >> a;
  if(a<1200){
    cout << "ABC" << endl;
  }
  else if(a>2799){
    cout << "AGC" << endl;
  }
  else{
    cout << "ARC" << endl;
  }
}
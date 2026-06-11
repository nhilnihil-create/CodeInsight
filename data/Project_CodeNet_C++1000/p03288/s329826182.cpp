#include<bits/stdc++.h>
using namespace std;
int main(){
  int r;
  cin >> r;
  if(r<1200){
    cout << "ABC" << endl;
  }
  else if(1200<=r&&r<2800){
    cout << "ARC" << endl;
  }
  else {
    cout << "AGC" << endl;
  }
}
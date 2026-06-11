#include <bits/stdc++.h>
using namespace std;

int main() {
  string d;
  int k=0;
  cin >> d;

  for(int i=0; i<d.size(); i++){
    if(d.at(i)=='1'){
      k = k+1;
    }
  }

  cout << k << endl;
}
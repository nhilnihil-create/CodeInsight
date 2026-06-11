#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C;
  cin >> A >> B >> C;
  
  if(C-A<=B && A<=C){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }
}

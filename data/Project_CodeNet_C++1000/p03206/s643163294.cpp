#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A;
  cin >> A;
  
  cout << "Christmas";
  if (A != 25){
    cout << ' ' << "Eve";
  }
  if (A==23 || A==22){
    cout << ' ' << "Eve";
  }
  if (A==22){
    cout << ' ' << "Eve";
  }
  cout << endl;
}
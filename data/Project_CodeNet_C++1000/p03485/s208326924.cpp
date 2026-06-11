#include <bits/stdc++.h>
using namespace std;

int main(){
 int A, B, C;
  cin >> A >> B;
  C = (A + B) / 2;
  if( ((A + B) % 2) != 0){
    C++;
  }
  cout << C << endl;
  return 0;
}
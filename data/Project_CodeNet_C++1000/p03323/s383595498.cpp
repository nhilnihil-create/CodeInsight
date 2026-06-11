#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B;
  cin >> A >> B;
  if(max(A,B)-min(A,B)<=1 && A+B<=16){
    cout << "Yay!" << endl;
  }
  else{
    cout << ":(" << endl;
  }
}
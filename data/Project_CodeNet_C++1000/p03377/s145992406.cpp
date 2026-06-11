#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A,B,X;
  cin >> A >> B >> X;
  if(A+B-1-X >= 0 && A <= X){
    cout << "YES" << endl;
    return 0;
  }
  cout << "NO" << endl;
}

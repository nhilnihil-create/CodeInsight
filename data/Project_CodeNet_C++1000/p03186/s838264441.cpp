#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A,B,C,X=0;
  cin >> A >> B >> C;
  if(C > B && A+B < C){
   cout << A+B+B+1 << endl;
    return 0;
  }
 cout << B+C << endl;
}

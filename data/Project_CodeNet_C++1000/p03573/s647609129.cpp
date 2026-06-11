#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int A, B, C;
  cin >> A >> B >> C;

  if (A == B && A != C){
    cout << C << endl;
  }
  else if (A == C && A != B)
  {
    cout << B << endl;
  }
  else
  {
    cout << A << endl;
  }
  
  
}
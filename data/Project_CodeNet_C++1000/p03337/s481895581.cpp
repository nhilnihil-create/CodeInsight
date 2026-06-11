#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int A, B;
  cin >> A >> B;

  if (A + B >= A - B && A + B >= A * B){
    cout << A + B << endl;
  }
  else if (A - B >= A + B && A - B >= A * B)
  {
    cout << A - B << endl;
  }
  else
  {
    cout << A * B << endl;
  }
  
  
}
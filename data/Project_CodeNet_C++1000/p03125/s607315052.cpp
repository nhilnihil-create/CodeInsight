#include <bits/stdc++.h>
using namespace std;
typedef int64_t i64;

int main()
{
  int A,B;
  cin >> A >> B;

  if(B%A == 0){
      cout << A + B << endl;
  }else{
      cout << B - A << endl;
  }
}

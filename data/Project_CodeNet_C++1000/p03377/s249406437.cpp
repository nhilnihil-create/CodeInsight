#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int A, B, X;
  cin >> A >> B >> X;

  if (A + B < X || A > X){
    cout << "NO" << endl;
  }
  else
  {
    cout << "YES" << endl;
  }
  
}
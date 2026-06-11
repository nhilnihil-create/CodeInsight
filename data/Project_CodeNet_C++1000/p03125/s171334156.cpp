#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int A, B;
  cin >> A >> B;

  cout << (B % A == 0 ? A + B : B - A) << endl;
}
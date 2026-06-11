#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, A, b;
  cin >> N >> A;
  b = N % 500;
  if(b = 0 || A >= b)
    cout << "Yes" << endl;
  else
    cout <<"No" << endl;
}
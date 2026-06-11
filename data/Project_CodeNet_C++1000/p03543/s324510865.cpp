#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int q1 = (n % 10);
  int n1 = (n / 10);
  int q2 = (n1 % 10);
  int n2 = (n1 / 10);
  int q3 = (n2 % 10);
  int n3 = (n2 / 10);
  if (q1 != q2){
    if (q2 != q3) cout << "No" << endl;
      else {
        if (q3 == (n3 % 10) ) cout << "Yes" << endl;
        else cout << "No" << endl;
      }
  }
  else {
    if (q2 == q3) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}
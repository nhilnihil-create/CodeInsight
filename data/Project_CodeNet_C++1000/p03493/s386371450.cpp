#include <bits/stdc++.h>
using namespace std;

int main() {
  int a;

  cin >> a ;
int b=a%100;
  cout << (a-b)%200/100+(b-b%10)%20/10+b%10<< endl;
}

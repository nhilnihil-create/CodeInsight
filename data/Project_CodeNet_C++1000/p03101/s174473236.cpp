#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a1,b1,a2,b2;
  cin >>a1>>b1>>a2>>b2;
  int kotae=a1*b1-a2*b1-a1*b2+a2*b2;
  cout <<kotae<<endl;
}
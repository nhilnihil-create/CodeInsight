#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B;
  cin>>A>>B;
  int plus=A+B;
  int minus=A-B;
  int times=A*B;
  int maximamu=max(plus,max(minus,times));
  cout<<maximamu<<endl;
}

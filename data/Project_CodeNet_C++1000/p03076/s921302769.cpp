#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  int a,b,c,d,e;
  int A,B,C,D,E;
  cin >> a >> b >> c >> d >> e;
  A=(a+9)%10+1;
  B=(b+9)%10+1;
  C=(c+9)%10+1;
  D=(d+9)%10+1;
  E=(e+9)%10+1;
  cout << ((a-1)/10+(b-1)/10+(c-1)/10+(d-1)/10+(e-1)/10+4)*10+min(A,min(B,min(C,min(D,E)))) << endl;
}
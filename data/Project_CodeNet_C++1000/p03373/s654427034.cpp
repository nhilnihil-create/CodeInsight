#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  int  A,B,C,X,Y;
  cin  >> A >> B >> C >> X >> Y;
  int t=10000000000;
  int a,b;
  for(int i=0; i<=100000; i++){
    a=X-i;
    b=Y-i;
    if(a<0){a=0;}
    if(b<0){b=0;}
    if(A*a+B*b+C*2*i<=t){t=A*a+B*b+C*2*i;}
  }
  cout << t <<endl;
}


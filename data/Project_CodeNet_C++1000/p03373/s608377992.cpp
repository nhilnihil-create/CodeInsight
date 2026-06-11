#include <bits/stdc++.h>
using namespace std;
int main(){
  int A,B,C,X,Y;
  cin>>A>>B>>C>>X>>Y;
  int l=min(X,Y), h=max(X,Y);
  vector<int> P={
    A*X+B*Y,
    2*C*X+max(0,Y-X)*B,
    max(0,X-Y)*A+2*C*Y,
  };
  cout<<min(P[0],min(P[1],P[2]))<<endl;
}
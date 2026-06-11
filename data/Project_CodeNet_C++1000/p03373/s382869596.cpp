#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C,X,Y;
  cin>>A>>B>>C>>X>>Y;
  
  int total=0;
  if(2*C<A+B) {
      int small=min(X,Y);
      total+=small*2*C;
      X-=small; Y-=small;
  }

  if(2*C<A) total+=X*2*C;
  else total+=X*A;

  if(2*C<B) total+=Y*2*C;
  else total+=Y*B;

  cout<<total<<endl;
  
}
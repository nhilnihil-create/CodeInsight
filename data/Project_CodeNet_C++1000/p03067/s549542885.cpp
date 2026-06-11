#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C;
  cin>>A>>B>>C;
  if(A<C&&C<B){
    cout<<"Yes"<< endl;
  }
  if(B<C&&C<A){
    cout<<"Yes"<< endl;
  }
  if(C<A&&C<B){
    cout<<"No"<< endl;
  }
  if(A<C&&B<C){
    cout<<"No"<< endl;
  }
  
}

#include <bits/stdc++.h>
using namespace std;
 
int main() {
int A;
  int B;
  int C;
  int D;
  cin>>A>>B>>C>>D;
  int l=A+B;
  int r=C+D;
  if(r==l)cout<<"Balanced"<<endl;
    if(r>l)cout<<"Right"<<endl;
      if(r<l)cout<<"Left"<<endl;
}
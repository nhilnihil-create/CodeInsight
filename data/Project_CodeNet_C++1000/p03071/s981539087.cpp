#include<bits/stdc++.h>
using namespace std;
int main()
{
  int A,B;
  cin>>A>>B;
  if(A==B)
    cout<<A+B;
  else
  if(A<B){
      B+=(B-1);
      cout<<B;}
  else
  {
    A+=(A-1);
   cout<<A;
  }
 return 0;
}
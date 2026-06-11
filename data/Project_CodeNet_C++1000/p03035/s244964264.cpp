#include<bits/stdc++.h>
using namespace std;
int main()
{
  int A,B;
  int amount=0;
  cin>>A>>B;
  if(A>= 13)
    cout<<B;
  else
    if(A>=6 && A<=12)
      cout<<B/2;
  else
    if(A>=0 && A<=5)
      cout<<"0";
  else 
    return 0;
}
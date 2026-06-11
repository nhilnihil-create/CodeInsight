#include<iostream>
using namespace std;
int main()
{
  int A,B,C;
  cin>>A>>B>>C;
  if(A>=1&&B>=1&&C>=1)
  {
    if(A+B>=C)
    cout<<"Yes"<<endl;
    else
   cout<<"No"<<endl; 
  }
}
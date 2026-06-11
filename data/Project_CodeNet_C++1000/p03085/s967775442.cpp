#include<bits/stdc++.h>
using namespace std;
 
int main(void)
{
  char b;
  cin>>b;
 
  switch (b)
  {
  case 'A':
    cout<<'T'<<endl;
    break;
    
  case 'T':
    cout<<'A'<<endl;
    break;
 
  case 'G':
    cout<<'C'<<endl;
    break;
 
  case 'C':
    cout<<'G'<<endl;
    break;
  
  default:
    break;
  }
}
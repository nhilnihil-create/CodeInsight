#include<iostream>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int x;
    x=n%k;
    if(x!=0)
      	cout<<"1";
  else
    	cout<<"0";
    return 0;
}
#include<iostream>
using namespace  std;
#define size 100
int main()
{
	int n,m,x,toll,squares[size],i,tolls_1=0;
	cin>>n>>m>>x;
	for(i=0;i<n+1;i++)
	{
		squares[i]=0;
	}
	for(i=0;i<m;i++)
	{
		cin>>toll;
		squares[toll] = 1;
	}
	for(i=0;i<x;i++)
	{
      tolls_1+=squares[i];
	}
      
    cout<<min(tolls_1,m-tolls_1);


}
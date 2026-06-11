#include<iostream>
using namespace std;
int main()
{
	 int r,d,x;
  	cin>>r>>d>>x;
  	int p=10;
  	while(p--)
    {
	cout<<r*x-d<<endl;
     x=r*x-d;
    }
}
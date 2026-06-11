#include<iostream>
using namespace std;
int main()
{
	char n;
	int c=0;
	for(int i=1;i<=4;i++)
	{
		cin>>n;
		if(n=='2')c++;
	}
	cout<<c;
	return 0;
}
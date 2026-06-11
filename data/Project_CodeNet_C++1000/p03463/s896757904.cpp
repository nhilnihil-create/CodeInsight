#include<iostream>
using namespace std;
int main()
{
	int n,x,y,tot=0;cin>>n>>x>>y;
	while(1)
	{
		if(x+1==y)
		{
			if(tot%2)cout<<"Alice";
			else cout<<"Borys";
			return 0;
		}
		if(!tot%2)x++;
		else y--;
		tot++;
		
	}
	return 0;
} 
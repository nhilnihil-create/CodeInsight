#include<iostream>
using namespace std;
char ch[510][510];
int main()
{
	int a,b;
	cin>>a>>b;
	for(int i=0;i<100;i++)
	{
		for(int j=0;j<100/2;j++)
		{
			ch[i][j]='.';
		}
	}
	for(int i=0;i<100;i++)
	{
		for(int j=100/2;j<100;j++)
		{
			ch[i][j]='#';
		}
	}
	a--;
	b--;
	for(int i=0;i<100;i+=2)
	{
		for(int j=0;j<50;j+=2)
		{
			if(b)
			{
				ch[i][j]='#';
				b--;
			}
			else
			{
				break;
			}
		}
		if(b==0)
		{
			break;
		}
	}
	for(int i=0;i<100;i+=2)
	{
		for(int j=51;j<100;j+=2)
		{
			if(a)
			{
				ch[i][j]='.';
				a--;
			}
			else
			{
				break;
			}
		}
		if(a==0)
		{
			break;
		}
	}
	cout<<"100 100\n";
	for(int i=0;i<100;i++)
	{
		ch[i][100]='\0';
		cout<<ch[i]<<endl;
	}
	return 0;
}
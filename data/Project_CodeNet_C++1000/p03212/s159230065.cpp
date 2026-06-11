#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,k=0;
	cin >> n;
	if(n>777777777)
	{
		n=777777777;
	}
	for(int i=357;i<=n;i+=2)
	{
		int a=i,a3=0,a5=0,a7=0;
		while(a>0)
		{
			if(a%10==3)
			{
				a3=1;
			}
			else if(a%10==5)
			{
				a5=1;
			}
			else if(a%10==7)
			{
				a7=1;
			}
			else
			{
				a3=0;
				break;
			}
			a/=10;
		}
		if(a3*a5*a7==1)
		{
			k++;
		}
	}
	cout << k << endl;
	return 0;
}

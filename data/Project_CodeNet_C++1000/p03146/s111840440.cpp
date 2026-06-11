#include  <bits/stdc++.h>
using namespace std;
int f(long int n);
int main()
{
	long int s,i,j;
	cin>>s;
	int a[100000];
	a[1]=s;
		for(i=2;i<10000;i++)
		{
			a[i]=f(a[i-1]);
			for(j=1;j<i;j++)
			{
				if(a[i]==a[j])
				{
					cout<<i<<endl;
					return 0;
				}
				
			}
		}
}


int f(long int n){
	long int s;
		if(n%2==0)
		{
			s=n/2;
		}
		else
		{
			s=(3*n)+1;
		}
		return s;
		
}
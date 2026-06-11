#include <bits/stdc++.h>
using namespace std;


int main()
{
	int n,m,c,i,j,b[300],count=0,sum=0,k;
	cin >> n >> m >> c;
	
	for(i=0;i<m;i++)
	{
		cin >> b[i];
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cin >> k;
			sum += k*b[j];
		}
		sum += c;
		if(sum>0) count++;
		sum=0;
	}
	
	cout <<  count ;
	
	
	

}
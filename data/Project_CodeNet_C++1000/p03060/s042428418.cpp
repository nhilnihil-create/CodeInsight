#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;

int main()
 {
 	long long int i,j,n,sum=0,max=0;
 	cin>>n;
 	int c[n],v[n],ans[n];
 	for(i=0;i<n;i++)
 		cin>>v[i];
 	for(i=0;i<n;i++)
 		cin>>c[i];
 	
 	
 	for(i=0;i<n;i++)
 	{
 		if(v[i]>=c[i])
 			ans[i]=	v[i]-c[i];
 		else
 			ans[i]=0;
 	}
 	for(i=0;i<n;i++)
 		sum+=ans[i];
 	cout<<sum<<endl;
 }
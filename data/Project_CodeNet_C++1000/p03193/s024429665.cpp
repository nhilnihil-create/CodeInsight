#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int a[1001],b[1001];
int main()
{
 	int n,i,x,y,sum=0;
 	cin>>n>>x>>y;
 	for(i=1;i<=n;i++)
 	{
 		cin>>a[i]>>b[i];
	 }
	 for(i=1;i<=n;i++)
	 {
	 	if(a[i]>=x&&b[i]>=y) sum++;
	 }
	 cout<<sum;
	return 0;
}

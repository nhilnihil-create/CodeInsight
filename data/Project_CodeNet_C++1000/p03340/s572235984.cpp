#include<bits/stdc++.h>
using namespace std;
const int N=200001;
int n;
int a[N];
long long suma,sumb,j;//要用long long
long long s;//要用long long，因为最多可能性为20000100000
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		while(suma+a[j+1]==(sumb^a[j+1])&&j+1<=n)//位运算加括号，因为运算级别较低 
		{
			suma=suma+a[j+1];
			sumb=(sumb^a[j+1]);
			j++;
		}
		s=s+j-i+1;
		suma=suma-a[i];
		sumb=(sumb^a[i]);
	}
	cout<<s; 
	return 0;
}
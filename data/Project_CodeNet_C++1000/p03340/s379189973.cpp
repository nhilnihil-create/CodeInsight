#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long n,a[300010],ret=0;
int main()
{
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];	
		int j=0,s=0,t=0;
		for(int i=1;i<=n;i++)
		{
			while((t^a[j+1])==s+a[j+1]&&j<n)
			{
				s+=a[j+1];
				t=t^a[j+1];
				j++;
			}
			if(t==s)
				ret+=(j-i+1);
			s-=a[i];
			t=t^a[i];
		}
		cout<<ret<<endl;
}
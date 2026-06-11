#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
long long a[n],g[n],gg[n];
for(int i=0;i<n;i++)cin>>a[i];
g[0]=a[0];
for(int i=1;i<n;i++)g[i]=__gcd(g[i-1],a[i]);
gg[n-1]=a[n-1];
for(int i=n-2;i>=0;i--)gg[i]=__gcd(gg[i+1],a[i]);


long long an=1;
for(int i=1;i<n-1;i++)
an=max(an,__gcd(g[i-1],gg[i+1]));
an=max({an,gg[0],gg[1],g[n-2]});
cout<<an<<endl;


}


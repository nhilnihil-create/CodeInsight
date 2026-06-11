#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define MAXX 100005

#define PI 3.14159265358979323846264338327950

#define ll signed long long int
int main()
{
	int b=0,f=0,k=0,l;
	string a;
	char n='0',s='1',z;
	cin>>a;
	l=a.size();
	while (l>b)
	{
		if (a[b]==n)
		f++;
		else
		k++;
		b++;
		z=s;
		s=n;
		n=z;
	}
	if (f<=k) 
	cout<<f;
	else
	cout<<k;
}
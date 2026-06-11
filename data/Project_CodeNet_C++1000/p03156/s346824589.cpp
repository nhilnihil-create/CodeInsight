#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fr(i,n,x) for(int i=0;i<n;i+=x)
#define pb push_back
int main(){
	int n,a,b;
	int a1=0,b1=0,c1=0;
	cin>>n>>a>>b;
	int x;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		if(x<=a)
		a1++;
		else
		if(x>a&&x<=b)
		b1++;
		else
		c1++;
	}
	cout<<min(a1,min(b1,c1));
}
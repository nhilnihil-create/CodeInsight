#include<bits/stdc++.h>
using namespace std;
int max(int x,int y)
{
	if(x>y) return x;
	else return y;
}
int gcd (int a,int b){
    while(b){
        int t=a%b;
        a=b;
        b=t;
    }
    return a;
}
int main()
{
	int sum=0;
	int n,a[10005],b[10005],c[100005];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	b[0]=a[0];
	for(int i=1;i<n;i++)
	{
		b[i]=gcd(b[i-1],a[i]);
	}
	c[n-1]=a[n-1];
	for(int i=n-2;i>=0;i--)
	{
		c[i]=gcd(c[i+1],a[i]);
	}
	for(int i=1;i<n-1;i++)
	{
		sum=max(gcd(b[i-1],c[i+1]),sum);
	}
	cout<<max(sum,max(c[1],b[n-2]))<<endl;
}
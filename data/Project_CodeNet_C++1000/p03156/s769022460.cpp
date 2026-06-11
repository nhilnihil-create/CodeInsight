#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<set>
using namespace std;
int n,h,w,a,b,c,i;
int main()
{
	int n,a,b,p,c[3]={0};
	cin>>n>>a>>b;
	for(int i=0;i<n;i++)
	{
		cin>>p;
		if(p<=a)c[0]++;
		else if(p<=b)c[1]++;
		else c[2]++;
	}
	sort(c,c+3);
	cout<<c[0]<<endl;
}
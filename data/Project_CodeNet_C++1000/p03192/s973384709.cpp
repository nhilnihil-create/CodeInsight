#include<bits/stdc++.h>
using namespace std;
int s,i,a[5],sum;
int main()
{
	cin>>s;
	a[1]=s%10;
	a[2]=(s%100-a[1])/10;
	a[3]=(s/100)%10;
	a[4]=s/1000;
	for(i=1;i<=4;i++)
	if(a[i]==2)
	sum++;
	cout<<sum<<endl;
	return 0;
}

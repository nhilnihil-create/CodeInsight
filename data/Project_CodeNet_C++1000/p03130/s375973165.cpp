#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	int a[4]={0},t;
	for(int i=0;i<6;i++)
	{
		cin>>t;
		a[t-1]++;
		if(a[t-1]==3)
		{
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES";
}
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int a,b;
	cin>>a>>b;
	int c=a+b;
	int d=a-b;
	int e=a*b;
	int f=max(c,d);
	int g=max(f,e);
	cout<<g<<endl;
	return 0;
}
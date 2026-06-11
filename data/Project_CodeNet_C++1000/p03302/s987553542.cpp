#include<bits/stdc++.h>
using namespace std;
int n,m,ans,cnt,a[1005],b[1005];
string s;
int main()
{
	cin>>n>>m;
	if(n+m==15)
	cout<<"+";
	else if(n*m==15)
	cout<<"*";
	else
	cout<<"x";
    return 0;
	} 
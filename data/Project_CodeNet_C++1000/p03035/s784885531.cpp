#include<bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
	cin>>n>>m;
	if(n>=13)cout<<m;
	else if(n>=6)cout<<m/2;
	else cout<<0;
}
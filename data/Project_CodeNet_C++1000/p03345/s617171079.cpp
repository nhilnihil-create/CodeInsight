#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
int main()
{
	ll a,b,c,d,k;
	cin>>a>>b>>c>>k;
	if(k%2==0)cout<<a-b<<endl;
	else if(k%2==1)cout<<b-a<<endl;
	return 0;
}
//#include "stdafx.h"
#include<bits/stdc++.h> 
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
/*int gcd(int n,int m)
{
	if(m==0)
		return n;

	return gcd(m, n % m);
}*/
int a,b,c,d;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>a>>b>>c>>d;
	if((abs(a-c)<=d)||(abs(a-b)<=d&&abs(b-c)<=d))
		cout<<"Yes\n";
	else
		cout<<"No\n";

	return 0;
}
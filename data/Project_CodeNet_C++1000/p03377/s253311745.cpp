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
int a,b,x;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>a>>b>>x;
	if(x<a||x>=(a+b))cout<<"NO\n";
	else 
		cout<<"YES\n";

	return 0;
}
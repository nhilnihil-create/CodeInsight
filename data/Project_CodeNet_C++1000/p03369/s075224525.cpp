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
string s;
int c;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]=='o')c++;

	cout<<700+(c*100)<<"\n";

	return 0;
}
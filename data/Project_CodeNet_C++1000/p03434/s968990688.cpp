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
bool comp (int x,int y){
	return x>y;
}
int n,a[101],A,B;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	set<char>st;

	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];

	sort(a,a+n,comp);

	for(int i=0;i<n;i++){
		if(i%2==0)A+=a[i];
		else
			B+=a[i];
	}
	cout<<A-B<<"\n";


	return 0;
}
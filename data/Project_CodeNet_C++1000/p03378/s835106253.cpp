//#include "stdafx.h"
#include<bits/stdc++.h> 
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
int n,m,x,c,q,a[101];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin >>n>>m>>x;
	for(int i=0;i<m;i++){
		cin>>a[i];

		if(a[i]>x&&a[i]!=n)c++;
		else if(a[i]<x)q++;
	}
	cout<<min(c,q)<<"\n";

	return 0;
}
//#include "stdafx.h"
#include<bits/stdc++.h> 
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
int sum,n,x,a[101];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin >>n>>x;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	sort(a,a+n);
	x-=sum;
	if(a[0]<=x)
		cout<<n+(x/a[0])<<"\n";
	else
		cout<<n<<"\n";

	return 0;
}
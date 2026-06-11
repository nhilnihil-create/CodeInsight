//#include "stdafx.h"
#include<bits/stdc++.h> 
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int a[3],k,ans;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	set<char>st;

	cin>>a[0]>>a[1]>>a[2]>>k;
	sort(a,a+3);
	ans=a[2];
	while(k--){
		ans*=2;
	}
	cout<<ans+a[0]+a[1]<<"\n";

	return 0;
}
//#include "stdafx.h"
#include<bits/stdc++.h> 
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
int ans,r,d,q,n,x,a[101],c;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin >>n>>d>>x;
	for(int i=0;i<n;i++)cin>>a[i];

	for(int i=0;i<n;i++){
		r=1;q=a[i];
		while(q<=d){
			q=(a[i]*r)+1;
			r++;
		}
		if(a[i]<d)
		ans+=r-2;
	}
	cout<<n+ans+x<<"\n";
	return 0;
}
//#include "stdafx.h"
#include<bits/stdc++.h> 
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
int ans,r,x,q;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin >>x;
	if(x==1)cout<<"1\n";
	else{
	for(int i=2;i<=(int)sqrt(x);i++){
		r=2;q=0;
		while(q<=x){
		    if(pow(i,r)>x)break;
		    else{
			q=pow(i,r);
			r++;}
		}
		ans=max(q,ans);
	}
	cout<<ans<<"\n";
	}
	return 0;
}
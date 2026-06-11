//#include "stdafx.h"
#include<bits/stdc++.h> 
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
int a,b,k,c;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	set<int>st;
	set<int>::iterator it;

	cin>>a>>b>>k;

	for(int i=a;(c<k&&i<=b);i++){
		c++;
		st.insert(i);
	}

	c=0;
	for(int i=b;(c<k&&i>=a);i--){
		c++;
		st.insert(i);
	}
	
	for(it=st.begin();it!=st.end();it++)
		cout<<*it<<"\n";
	
	return 0;
}


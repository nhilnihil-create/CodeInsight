//#include "stdafx.h"
#include<bits/stdc++.h> 
#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;
int n,q;
long long ans;
int main()
{
	cin>>n;
	for(int i=n;i>=0;i--){
		q=sqrt(i);
		ans=q*q;
		if(ans==i){
			cout<<i<<"\n";
			break;}
	}

	return 0;
}


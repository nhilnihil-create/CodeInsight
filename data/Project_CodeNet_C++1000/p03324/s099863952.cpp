//#include "stdafx.h"
#include<bits/stdc++.h> 
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int d,n;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	cin>>d>>n;
	if(n==100){
		++n;
		if(d==0)
		cout<<n<<"\n";
		else if(d==1)
			cout<<n*100<<"\n";
		else if(d==2)
			cout<<n*10000<<"\n";
	}
	else if(d==0)
		cout<<n<<"\n";
	else if(d==1){
		n*=100;
		cout<<n<<"\n";
	}
	else if(d==2){
		n*=10000;
		cout<<n<<"\n";
	}
	
	
	return 0;
}


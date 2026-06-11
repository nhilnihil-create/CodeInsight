//#include "stdafx.h"
#include<bits/stdc++.h> 
#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;
string a,b;
int main()
{
	cin>>a>>b;
	reverse(a.begin(),a.end());
	if(a==b)
		cout<<"YES\n";
	else
		cout<<"NO\n";

	return 0;
}


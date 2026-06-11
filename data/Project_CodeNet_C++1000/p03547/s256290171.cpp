//#include "stdafx.h"
#include<bits/stdc++.h> 
#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;
char x,y;
int main()
{
	cin>>x>>y;
	if(x<y)
		cout<<"<\n";
	else if(x>y)
		cout<<">\n";
	else 
		cout<<"=\n";

	return 0;
}


#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	int x=max({a,b,c});
	int y=min({a,b,c});
	cout<<x-y;
}
#include <iostream>
	#include <string>
	#include <stdio.h>
	#include <queue>
	#include <stack>
	#include <string.h>
	#include <algorithm>
	#include <math.h>
	//#include <bits/stdc++.h>
	#define ll long long
	#define wtcl return
	using namespace std;
	
	inline int read()
	{
	    ll s = 0, f = 1;
	    char ch = getchar();
	    for(; ch < '0' || ch > '9'; ch = getchar()) if(ch == '-') f = - 1;
	    for(; ch >= '0' && ch <= '9'; ch = getchar()) s = ((s << 3ll) + (s << 1ll) + (ch ^ 48ll));
	    return s * f ;
	}
	
	int main()
	{
	    ll a,b;
	    while(cin>>a>>b)
	    {
	    	ll x = (a-2)*(b-2);
	    	if(x<0)
	    	x = -x;
	    	cout<<x<<endl;
		}
	    wtcl 0;
	}
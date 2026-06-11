/*
problem's name: atcoder arc 94-b
statue:Accepted
writer:Patrick_y
*/
#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <string>
#include <stack>
#include <set>
#include <deque>
#include <cctype>
#include <sstream>
#include <math.h>
#include <stdio.h>
#include <time.h>
#define mp make_pair
typedef long long ll;
using namespace std;
const ll INF=20050208;
/*------------main part------------*/




int main()
{
	ll n;
	cin>>n;
	ll a,b,p;
	ll ans=0;
	while(n--)
	{
		cin>>a>>b;
		p=a*b;
		ll t=sqrt(p);
		if(t*(t+1)<p)
		{
			ans=t*2-1;
		}
		else if(t*t==p)
		{
			if(a==b)
			{
				ans=(t-1)*2;
			}
			else
			{
				ans=(t-1)*2-1;
			}
		}
		else
		{
			ans=(t-1)*2;
		}
		cout<<ans<<endl;
	}
	return 0;
}

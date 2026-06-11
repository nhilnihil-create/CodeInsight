#include<bits/stdc++.h> 
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <assert.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n,m;
	cin>>n>>m;
	vector<ll> v;
	for(ll i=1;i*i<=m;i++) if(m%i==0) v.push_back(m/i),v.push_back(i);
	sort(v.begin(),v.end());
	ll ans=m;
	for(ll i=0;i<v.size();i++)
	{
//		printf("%lld ",v[i]);
		if(v[i]>=n)
		{
			ans=v[i];break;
		}
	}
	cout<<m/ans;
}
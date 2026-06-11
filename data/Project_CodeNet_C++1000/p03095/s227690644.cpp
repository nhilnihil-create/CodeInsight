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
	int n;
	string s;
	cin>>n>>s;
	ll a[200]={0};
	ll mod=1e9+7;
	for(ll i=0;i<s.size();i++)
	{
		a[s[i]-'a']++;
	 } 
	 ll ans=1;
	 for(ll i=0;i<26;i++)
	 {
	 	ans*=a[i]+1;
	 	ans%=mod;
	 }
	 cout<<ans-1;
}
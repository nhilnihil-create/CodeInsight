#include<bits/stdc++.h>
#include <iostream>
#include <cstdio>
#define endl '\n'
using namespace std;
typedef long long ll;
int main()
{
	ll n,x,a[101];
	cin>>n>>x;
	for(int i = 0; i<n; i++)
		cin>>a[i];
	sort(a,a+n);
	//a.reverse();
	int d,cnt = 0;
	for(int i = 0; i<n; i++)
	{
		if(x>=a[i])cnt++,x = x-a[i];
		else break;
	}
	if(cnt == n && x)cnt--;
	cout<<cnt<<endl;
	return 0;
}
//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<map>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0)
typedef long long ll;
int main()
{
	//fast;
	
	ll tc,x,sum=0,n;
	cin>>tc;
	n=tc;
	while(tc--)
	{
		cin>>x;
		sum+=x;
	}
	cout<<sum-n<<endl;
}
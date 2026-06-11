#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<stack>
#include<iostream>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define MOD 1000000007
#define vec(a) vector<int>a
using namespace std;


int main()
{
#ifndef ONLINE_JUDGE
	freopen("output.txt", "w", stdout);
	freopen("input.txt", "r", stdin);
#endif
	ll t,t1,c,i,j,k,l,a,n,d;
		cin>>n>>t;
		k=0;
		for(i=0;i<n;i++)
		{
			cin>>c>>t1;
			if(t1<=t)
			{
				if(k==0)
					k=c;
				else
				{
					if(c<k)
						k=c;
				}
			}
		}
		if(k!=0)
			cout<<k<<"\n";
		else
			cout<<"TLE";
		return 0;
}
	
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pb push_back

int main()
{
	int n;
	cin>>n;
	vector<int>store;
	store.pb(1);
	int ways[n+1];
	for(int i=0;i<=n;i++)
	{
		ways[i]=100001;
	}
	int x=1,y=1;
	
			while(x*9<=n){
				store.pb(x*9);
				//ways[x*9]=1;
				x*=9;
			}
		while(6*y<=n)
	{
			store.pb(6*y);
			//ways[6*y]=1;
			y*=6;
	}
	sort(store.begin(),store.end());
	ways[0]=0;
	ways[1]=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<store.size();j++)
		{
			if(store[j]<=i){
			ways[i]=min(ways[i],1+ways[i-store[j]]);}
			else
				break;
		}
	}
	cout<<ways[n]<<"\n";
	}

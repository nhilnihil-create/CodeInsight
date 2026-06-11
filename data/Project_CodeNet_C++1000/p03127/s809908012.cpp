#include<iostream>
using namespace std;
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#define int long long int
int function2(int memo[],int turn[],int n,map<int,int> &sticks)
{
	if(n<0)
	{
		return -1000000000;
	}
	if(n==0)
	{
		return 0;
	}
	if(memo[n]!=-1)
	{
		return memo[n];
	}
	else
	{
		map<int,set<int>> mp;
		int here=-1000000000;
		mp[here].insert(-1);
		for(auto &p:sticks)
		{
			int val=1+function2(memo,turn,n-p.second,sticks);
			mp[val].insert(p.first);
		}
		auto it=mp.end();
		it--;
		int answer=*it->second.rbegin();
		turn[n]=answer;
		memo[n]=it->first;
		return it->first;
	}
}
int32_t main()
{
	int answer=0;
	int n;
	cin>>n;
	int j;
	for(j=0;j<n;j++)
	{
		int x;
		cin>>x;
		answer=__gcd(answer,x);
	}
	cout<<answer<<endl;
}

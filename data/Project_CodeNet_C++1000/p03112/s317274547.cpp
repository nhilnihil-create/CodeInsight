#include<iostream>
using namespace std;
#include<vector>
#include<set>
#include<algorithm>
#define int long long int
#define inf 10000000000000
int function2(int x,int val1,int val2)
{
	int here1=abs(x-val1)+abs(val1-val2);
	int here2=abs(x-val2)+abs(val1-val2);
	return min(here1,here2);
}
int32_t main()
{
	int a,b,q;
	cin>>a>>b>>q;
	set<int> st1,st2;
	int j;
	for(j=0;j<a;j++)
	{
		int x;
		cin>>x;
		st1.insert(x);
	}
	for(j=0;j<b;j++)
	{
		int x;
		cin>>x;
		st2.insert(x);
	}
	while(q--)
	{
		int x;
		cin>>x;
		int val1=inf,val2=inf,val3=inf,val4=inf;
		auto it=st1.lower_bound(x);
		if(it!=st1.end())
		{
			val1=*it;
		}
		if(*st1.begin()<x)
		{
			auto it2=st1.lower_bound(x);
			it2--;
			val2=*it2;
		}
		it=st2.lower_bound(x);
		if(it!=st2.end())
		{
			val3=*it;
		}
		if(*st2.begin()<x)
		{
			auto it2=st2.lower_bound(x);
			it2--;
			val4=*it2;
		}
		int here1=function2(x,val1,val3);
		int here2=function2(x,val1,val4);
		int here3=function2(x,val2,val3);
		int here4=function2(x,val2,val4);
		int answer=inf;
		int here=min(min(here1,here2),min(here3,here4));
		answer=min(answer,here);
		cout<<answer<<endl;
	}
}

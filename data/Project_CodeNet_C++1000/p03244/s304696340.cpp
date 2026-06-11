#include<bits/stdc++.h>
using namespace std;
using ll = long long;


int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto &i:a)cin >> i;
	
	vector<int> b(100001),c(100001);
	for(int i = 0;i<n;i++)
	{
		//cout<<a[i]<<endl
		if(i&1)b[a[i]]++;
		else c[a[i]]++;
	}
	//sort(b.begin(),b.end(),greater<>());
	//sort(c.begin(),c.end(),greater<>());
	vector<pair<int,int>> B,C;
	int b1=0,b2=0,c1=0,c2=0;
	int bb=-1,bb2=-1,cc=-1,cc2=-1;
	for(int i =0 ;i<100001;i++)
	{
		if(b[i])
		{
			B.emplace_back(b[i],i);
		}
		if(c[i])
		{
			C.emplace_back(c[i],i);
		}
	}
	//cout<<c[105]<<' '<<b[105]<<endl;
	sort(B.rbegin(),B.rend());
	sort(C.rbegin(),C.rend());
	b1 = B[0].first;bb = B[0].second;
	c1 = C[0].first;cc = C[0].second;
	if(B.size()>1)
	{
		b2 = B[1].first;bb2 = B[1].second;
	}
	if(C.size()>1)
	{
		c2 = C[1].first;cc2 = C[1].second;
	}

	if(bb==cc)
	{
		if(c1>b1)
		{
			cout<<n-c1-b2<<endl;
		}
		else if(c1<b1)
		{
			cout<<n-b1-c2<<endl;
		}
		else if(c2>b2)
		{
			cout<<n-c2-b1<<endl;
		}
		else if(c2<b2)
		{
			cout<<n-b2-c1<<endl;
		}
		else
		{
			//cout<<c2<<endl;
			cout<<n-b1-c2<<endl;
		}
	}
	else 
	{
		//cout<<';'<<endl;
		cout<<n-b1-c1<<endl;
	}
}
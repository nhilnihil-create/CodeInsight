#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main()
{	
	int n,k,a;
	map<int,int>m;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		m[a]++;
	}
	vector<pair<int,int>>v;
	for(auto i=m.begin();i!=m.end();i++) 
	{
		v.push_back(make_pair(i->second,i->first));
	}
	sort(v.begin(),v.end());
	int size=v.size(),sum=0;
	for(int i=0;i<v.size();i++)
	{
		if(size>k)
		{
			sum+=v[i].first;
			size--;
		}
		else break;
	}
	cout<<sum<<endl;
	return 0;
}
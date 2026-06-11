#include <bits/stdc++.h>
using namespace std;
string s; 
int n;
int main()
{
	cin>>s;
	n=s.size();
	if(s.back()=='1')
	{
		puts("-1");
		return 0;
	}
	s.pop_back();
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!=s[s.size()-i-1])
		{
			puts("-1");
			return 0;
		}
	}
	if(s[0]=='0' || s.back()=='0')
	{
		puts("-1");
		return 0;
	}
	vector <int> v;
	vector <pair<int,int> > ans;
	int node=1;
	int last=0;
	for(int i=0;i<s.size();i++)
	{
	//	if(i>s.size()-i-1)continue;
		
		if(s[i]=='1')
		{
			int size_c=i+1-last;
			last=i+1;
			v.push_back(node);
			for(int j=1;j<size_c;j++)
			{
				ans.push_back(make_pair(node,node+j));
			}
			node+=size_c;
			if(node>n)
			{
				puts("-1");
				return 0;
			}
		}
	}
	while(node<=n)
	{
		v.push_back(node);
		node++;
	}
	for(int i=1;i<v.size();i++)
	{
		ans.push_back(make_pair(v[i-1],v[i]));
	}
	for(int i=0;i<n-1;i++)
	{
		cout<<ans[i].first<<" "<<ans[i].second<<endl;
	}
	return 0;
}
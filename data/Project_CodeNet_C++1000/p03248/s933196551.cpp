#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+4;
string s;
vector <int> v;
int deg[N];
int main()
{
	cin>>s;
	int n = s.length();
	s = "a" + s;
	if(s[1] == '0' || s[n] == '1') return cout<<-1, 0;
	
	for(int i=1;i<n;i++)
	{
		if(s[i] == '1')
			v.push_back(i);
			
		if(s[i] != s[n-i]) return cout<<-1, 0;
	}

	deg[1] = v[0]-1; 
	for(int i=1;i<(int)v.size();i++)
	{
		deg[i+1] = v[i]-v[i-1]-1;
	}

	int run = 1, idx = 1;
	// for(int i=1;i<=(int)v.size();i++)
	// {
	// 	cout<<deg[i]<<' ';
	// }
	for(int i=1;i<=(int)v.size();i++)
	{
		// cout<<deg[i]<<' ';
		for(int j=1;j<=deg[i];j++)
		{
			cout<<idx<<' '<<++run<<'\n';
		}
		if(run != n)
			cout<<idx<<' '<<++run<<'\n';
		idx = run;
	}
}
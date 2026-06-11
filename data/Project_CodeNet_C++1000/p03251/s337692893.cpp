#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main()	
{
	int n,m,x,y,a,b;
	vector<int>v,w;
	cin>>n>>m>>x>>y;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		v.push_back(a);
	}
	for(int i=0;i<m;i++)
	{
		cin>>b;
		w.push_back(b);
	}
	sort(v.begin(),v.end());
	sort(w.begin(),w.end());
	for(int i=max(x,v[v.size()-1])+1;i<=100;i++)
	{
		if(i<=min(y,w[0]))
		{
			cout<<"No War"<<endl;
			return 0;
		}
	}
	cout<<"War"<<endl;
	return 0;
}
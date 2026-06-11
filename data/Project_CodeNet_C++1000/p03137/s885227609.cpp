#include<bits/stdc++.h>
//#include<atcoder/all>
using namespace std;
using ll = long long;

int main()
{
	int n,m;
	cin >> n >> m;
	n = min(n,m);
	vector<int> a(m);
	for(auto &i:a)cin >> i;
	sort(a.begin(),a.end());
	vector<pair<int,int>> vp(m-1);
	for(int i = 0;i<m-1;i++)
	{
		vp[i] = make_pair(a[i+1]-a[i],i+1);
	}
	vp.emplace_back(10000000,0);
	sort(vp.rbegin(),vp.rend());
	ll ans = 0;
	vp.insert(vp.begin()+n,make_pair(0,m));
	for(int i = 0;i<n;i++)
	{
		ans += a[vp[i+1].second-1]-a[vp[i].second];
	}
	cout<<ans<<endl;
	
	
}

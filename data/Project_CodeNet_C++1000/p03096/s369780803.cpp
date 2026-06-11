#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

int main()
{
	int n;
	cin >> n;
	vector<ll> c(n);
	for(auto &i:c)cin >> i;
	c.erase(unique(c.begin(),c.end()),c.end());
	//for(auto &i:c)cout<<i<<endl;
	vector<int> tmp(200001,0);
	
	tmp[c[0]]=1;
	for(int i = 1;i<c.size();i++)
	{
		if(tmp[c[i]])
		{
			(tmp[c[i]] += tmp[c[i-1]])%=MOD;
		}
		else
		{
			(tmp[c[i]] = tmp[c[i-1]])%=MOD;
		}
	}
	cout<<tmp[c.back()]<<endl;
}
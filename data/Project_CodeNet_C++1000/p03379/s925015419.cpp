#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


int main()
{
	int N;
	cin>>N;
	vector<ll> X(N);
	vector<ll> vec(N);
	rep(i,N)
	{
		cin>>X[i];
		vec[i]=X[i];
	}
	ll left_mid=0;
	ll right_mid=0;
	sort(vec.begin(),vec.end());
	left_mid=vec[N/2-1];
	right_mid=vec[N/2];
	map<ll,int> m;
	for(int i=0;i<vec.size();i++)
	{
		m[vec[i]]=i;
	}
	for(ll x : X)
	{
		if(m[x]<N/2)
		{
			cout<<right_mid<<endl;
		}
		else
		{
			cout<<left_mid<<endl;
		}
	}
	return 0;
}

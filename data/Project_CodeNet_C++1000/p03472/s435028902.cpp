#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


int main()
{
	int N,H;
	cin>>N>>H;
	vector<pair<int,int>> ab(N,make_pair<int,int>(-1,-1));
	rep(i,N)
	{
		cin>>ab[i].first>>ab[i].second;
	}
	sort(ab.begin(),ab.end(),[](auto const &x,auto const &y){
			return x.first>y.first;
			});
	pair<int,int> best=ab[0];
	vector<int> throw_sord;
	throw_sord.push_back(best.second);
	for(int i=1;i<N;i++)
	{
		if(best.first<=ab[i].second)
		{
			throw_sord.push_back(ab[i].second);
		}
	}
	sort(throw_sord.begin(),throw_sord.end(),greater<int>());
	int ans=0;
	for(int s : throw_sord)
	{
		H-=s;
		ans++;
		if(H<=0) break;
	}
	if(H<=0)
	{
		cout<<ans<<endl;
	}
	else
	{
		cout<<ans+(H+best.first-1)/best.first<<endl;
	}
	return 0;
}

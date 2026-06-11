#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <set>
#include <cmath>
#include <vector>
#include <queue>
#include <ctime>
#include <sstream>
#include <utility>
#include <bitset>
#include <stack>

using namespace std;

#define MP make_pair 
#define PB push_back 
#define INF (1000000007) 
#define eps 1e-9
#define MOD (998244353) 
#define IOS ios::sync_with_stdio(false)

typedef pair<int,int> pii ;
typedef pair<double,double> pdd ;
typedef long long ll ;

int n;
pii p[200005];
bool del[100005];
priority_queue<pii> ml,mr;

inline ll sol(bool dir)
{
	while(!ml.empty()) ml.pop();
	while(!mr.empty()) mr.pop();
	memset(del,0,sizeof(del));
	for(int i=1;i<=n;i++) 
	{
		ml.push(MP(p[i].first,i));
		mr.push(MP(-p[i].second,i));
	}
	ll ret=0;
	int cur=0;
	for(int i=1;i<=n;i++,dir=!dir)
	{

		if(dir==1)
		{
			if(ml.empty()) break;
			int t=ml.top().second;
			while(del[t] && !ml.empty())
			{
				ml.pop();
				if(!ml.empty()) t=ml.top().second;
			}
			if(ml.empty() || (p[t].first<=cur && p[t].second>=cur)) break;
//			cout<<cur<<" "<<ml.top().first<<endl;
			ret+=abs((ll)ml.top().first-(ll)cur);
//			cout<<"L"<<(ll)ml.top().first<<endl;
			cur=ml.top().first;
			del[t]=1;
			ml.pop();
		}
		else 
		{
			if(mr.empty()) break;
			int t=mr.top().second;
			while(del[t] && !mr.empty())
			{
				mr.pop();
				if(!mr.empty()) t=mr.top().second;
			}
//			cout<<p[t].first<<" "<<p[t].second<<endl;
			if(mr.empty() || (p[t].first<=cur && p[t].second>=cur)) break;
//			cout<<cur<<" "<<-mr.top().first<<endl;
			ret+=abs((ll)-mr.top().first-(ll)cur);
//			cout<<"L"<<(ll)-mr.top().first<<endl;
			cur=(ll)-mr.top().first;
			del[t]=1;
			mr.pop();
		}	
//		cout<<dir<<" "<<cur<<" "<<ret<<endl;
	}
	ret+=abs(cur);
//	cout<<"ret="<<ret<<endl;
	return ret;
}
int main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>p[i].first>>p[i].second;
	}
	ll ans=0;
	ans=max(sol(1),sol(0));
	cout<<ans;
	return 0;
}
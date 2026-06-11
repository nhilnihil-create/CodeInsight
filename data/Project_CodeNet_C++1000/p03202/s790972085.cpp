#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
#define MOD 1000000007
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fll
typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
const int maxn=2e5+10;
int n;
int A[maxn];
map<int,int> mp;
vector<int> ids,toe;
bool check(int ans)
{
	mp.clear();
//	cout<<ans<<endl;
	for(int i=0;i<ids.size();i++)
	{
//		cout<<i<<endl;
		int pos=A[ids[i]];
		toe.clear();
		for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++)
		{
			if(it->first>pos)toe.push_back(it->first);
		}
		for(int j=0;j<toe.size();j++)
			mp.erase(toe[j]);
		while(pos>=1&&mp.count(pos)&&mp[pos]+1>=ans)pos--;
		if(pos<1)pos=1;
		mp[pos]++;
		if(mp[pos]>=ans)return 0;
		toe.clear();
		for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++)
		{
			if(it->first>pos)toe.push_back(it->first);
		}
		for(int j=0;j<toe.size();j++)
			mp.erase(toe[j]);
	}
	return 1;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
		if(i&&A[i]<=A[i-1])
			ids.push_back(i);
	}
	int l=0,r=n;
//	cout<<ids.size()<<endl;
	while(r-l>1)
	{
		int mid=(l+r)/2;
		if(check(mid))r=mid;
		else l=mid;
	}
	printf("%d\n",r);
	return 0;
}
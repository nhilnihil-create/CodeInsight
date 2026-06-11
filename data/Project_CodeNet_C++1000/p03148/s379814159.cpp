#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<pair<long,int> >A;
int n,k;
bool used[1<<17];
main()
{
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		int t;long d;cin>>t>>d;
		A.push_back(make_pair(-d,t));
	}
	sort(A.begin(),A.end());
	long ans=0,now=0,cnt=0;
	vector<long>t;
	for(int i=0;i<k;i++)
	{
		now-=A[i].first;
		if(!used[A[i].second])
		{
			used[A[i].second]=1;
			cnt++;
		}
		else
		{
			t.push_back(A[i].first);
		}
	}
	int id=k;
	sort(t.begin(),t.end());
	ans=now+cnt*cnt;
	while(!t.empty()&&id<n)
	{
		if(!used[A[id].second])
		{
			now+=t.back();
			t.pop_back();
			now-=A[id].first;
			used[A[id].second]=1;
			cnt++;
			ans=max(ans,now+cnt*cnt);
		}
		id++;
	}
	cout<<ans<<endl;
}
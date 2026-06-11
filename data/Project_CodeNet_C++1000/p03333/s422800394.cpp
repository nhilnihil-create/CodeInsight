#include<bits/stdc++.h>
using namespace std;

#define int long long

int N;
int L[100010];
int R[100010];

main()
{
	ios::sync_with_stdio(false);
	
	cin>>N;
	for(int i=1;i<=N;i++)
	{
		cin>>L[i]>>R[i];
	}
	sort(L+1,L+1+N); reverse(L+1,L+1+N);
	sort(R+1,R+1+N);
	int ml=0,mr=0;
	int ans=0;
	for(int i=1;i<=N;i++)
	{
		if(L[i]<=mr || i==N)
		{
			ans+=abs(mr);
			break;
		}
		ml=L[i];
		ans+=ml-mr;
		if(R[i]>=ml)
		{
			ans+=abs(ml);
			break;
		}
		mr=R[i];
		ans+=ml-mr;
	}
	int ans2=ans;
	
	ml=0,mr=0;
	ans=0;
	for(int i=1;i<=N;i++)
	{
		if(R[i]>=ml || i==N)
		{
			ans+=abs(ml);
			break;
		}
		mr=R[i];
		ans+=ml-mr;
		if(L[i]<=mr)
		{
			ans+=abs(mr);
			break;
		}
		ml=L[i];
		ans+=ml-mr;
	}
	cout<<max(ans,ans2)<<endl;
}

/*
	|- L[i]-pos (pos<L[i])
dis=|  0 (L[i]<=pos<=R[i])
	|- pos-R[i] (pos>R[i])
*/
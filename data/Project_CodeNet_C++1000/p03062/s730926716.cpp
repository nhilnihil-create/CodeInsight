#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


int main()
{
	int N;
	cin>>N;
	vector<int> A(N);
	int neg_cnt=0;
	ll ans=0;
	int min_v=1e9+1;
	rep(i,N)
	{
		cin>>A[i];
		neg_cnt+=A[i]<0;
		ans+=abs(A[i]);
		min_v=min(min_v,abs(A[i]));
	}
	if(neg_cnt%2==0)
	{
		cout<<ans<<endl;
	}
	else
	{
		cout<<ans-2*min_v<<endl;
	}
	return 0;
}

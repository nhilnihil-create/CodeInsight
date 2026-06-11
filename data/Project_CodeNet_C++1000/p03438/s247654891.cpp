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
	vector<int> B(N);
	rep(i,N) cin>>A[i];
	rep(i,N) cin>>B[i];
	ll r=0;
	rep(i,N)
	{
		if(A[i]<=B[i])
		{
			r+=(B[i]-A[i])/2;
		}
	}
	rep(i,N)
	{
		if(A[i]>B[i])
		{
			if(A[i]-B[i]<=r)
			{
				r-=A[i]-B[i];
			}
			else
			{
				cout<<"No"<<endl;
				return 0;
			}
		}
	}
	cout<<"Yes"<<endl;
	return 0;
}

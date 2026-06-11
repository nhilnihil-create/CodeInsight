#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<climits>
#include<iostream>
#include<sstream>
#include<utility>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
#include<stack>
#include<functional>
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

vector<ll>inarr(ll N)
{
	ll t;
	vector<ll>r;
	for(ll i=0;i<N;i++)
	{
		cin>>t;
		r.push_back(t);
	}
	return r;
}

int main()
{
	ll N;
	ll T=0L;
	cin>>N;
	auto A=inarr(N);
	auto B=inarr(N);
	for(int i=0;i<N;i++)
	{
		if(A[i]>B[i])
		{
			T-=A[i]-B[i];
		}
		else if(A[i]<B[i])
		{
			T+=(B[i]-A[i])/2;
		}
	}
	cout<<(T>=0?"Yes":"No")<<endl;
	return 0;
}
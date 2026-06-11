#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


int main()
{
	ll K,A,B;
	cin>>K>>A>>B;
	if(A>=B-1||K<A+1) cout<<K+1<<endl;
	else
	{
		K-=A-1;
		cout<<B+(K/2-1)*(B-A)+K%2<<endl;
	}
	return 0;
}

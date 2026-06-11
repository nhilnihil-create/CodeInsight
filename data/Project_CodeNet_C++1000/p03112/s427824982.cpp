#pragma GCC optimize ("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse4")
#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
#define sz(x) (int)(x).size();
#define all(x) x.begin(), x.end()
#define trav(i,a) for(auto &i:a) 
inline int in(){int x;scanf("%lld",&x);return x;}
const int inf=1e18;
int32_t main()
{
	int A=in();int B=in();int q=in();int x;
	vector<int> s(A+2),t(B+2);
	s[0]=t[0]=-inf;
	for(int i=1;i<=A;i++)s[i]=in();
	for(int i=1;i<=B;i++)t[i]=in();
	s[A+1]=inf;t[B+1]=inf;
	
	while(q--)
	{
		x=in();
		int s1=*lower_bound(all(s),x);
		int t1=*lower_bound(all(t),x);
		auto i=upper_bound(all(s),x);i--;
		int s2=*i;
		i=upper_bound(all(t),x);i--;int t2=*i;
		//cout<<s1<<" "<<s2<<" "<<t1<<" "<<t2<<"\n";
		//s1t1 or t1s1
		int s1t1=abs(t1-s1)+min(abs(x-s1),abs(x-t1));
		//s1t2 or t2s1
		int s1t2=abs(t2-s1)+min(abs(x-t2),abs(x-s1));
		//s2t1 or t1s2
		int s2t1=abs(s2-t1)+min(abs(x-t1),abs(x-s2));
		//s2t2
		int s2t2=abs(s2-t2)+min(abs(s2-x),abs(t2-x));
		
		cout<<min({s1t1,s1t2,s2t1,s2t2})<<"\n";
		
	}
	
	
}
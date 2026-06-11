#include<cstdio>
#include<vector>
#include<algorithm>


using namespace std;
using vc=vector<char>;
using vi=vector<int>;
using ll=long long;
using vll=vector<ll>;


ll calc(int n, vc&s, int k)
{
	ll ans=0LL;
	ll nd=0, nm=0, ndm=0;

	for(int i=0;i<n;i++)
	{
		if(i-k>=0)
		{
			if(s[i-k]=='D') nd--, ndm-=nm;
			if(s[i-k]=='M') nm--;
		}
		if(s[i]=='D') nd++;
		if(s[i]=='M') nm++, ndm+=nd;
		if(s[i]=='C') ans+=ndm;
	}
	return ans;
}


int main(void)
{
	int n, q;
	vc s(1000000+2);

	while(scanf("%d%1000000s%d", &n, &s[0], &q)==3)
	{
		vi k(q);
		vll nd(n), ndm(n);

		for(int i=0;i<q;i++)
		{
			scanf("%d", &k[i]);
		}

		for(int i=0;i<q;i++)
		{
			printf("%lld\n", calc(n, s, k[i]));
		}
	}

	return 0;
}

#include<bits/stdc++.h>

#define SORT(v) sort(v.begin(),v.end())
#define si(n) scanf("%d",&n)
#define sii(n,m) scanf("%d %d",&n,&m)
#define sl(n) scanf("%lld",&n)
#define sll(n,m) scanf("%lld %lld",&n,&m)
#define ss(cad) scanf("%s",cad)
#define PB push_back
#define fst first
#define scn second
#define DBG(x) cerr << #x << " = " << (x) << endl; 
#define M 1000000007
#define N_MAX 100010

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vl;
typedef pair<int,int> pi;
typedef vector<pi> vp;

int main()
{
	int m, k;
	sii(m, k);

	if(m <= 1)
	{
		if(k == 0)
		{
			printf("0 0");
			for(int i = 1; i < (1<<m); i++)
				printf(" %d %d", i, i);
			printf("\n");
		}
		else
			printf("-1\n");
	}
	else if(k < (1<<m))
	{
		if(k == 0)
		{
			printf("0 0");
			for(int i = 1; i < (1<<m); i++)
				printf(" %d %d", i, i);
			printf("\n");
		}
		else
		{
			stack<int> pila;
			vi ans;
			ans.push_back(0);
			ans.push_back(k);
			for(int i = 1; i < (1<<m); i++)
			{
				if(i == k)
					continue;
				ans.push_back(i);
				pila.push(i);
			}

			ans.push_back(k);
			ans.push_back(0);
			while(!pila.empty())
			{
				ans.push_back(pila.top());
				pila.pop();
			}
			printf("%d", ans[0]);
			for(int i = 1; i < ans.size(); i++)
				printf(" %d", ans[i]);
			printf("\n");
		}
	}
	else
		printf("-1\n");
    return 0;
}

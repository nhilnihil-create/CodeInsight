#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ALL(v) v.begin(), v.end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1000000007;

struct prog
{
	int s,t,c;
};

bool cmp(prog a,prog b)
{
	if(a.c!=b.c)return a.c<b.c;
	return a.s <= b.s;
}

int main()
{
	int n,c;
	cin >> n >> c;
	vector<prog> p(n);
	vector<int> imos(200010);
	rep(i,n)
	{
		cin >> p[i].s >> p[i].t >> p[i].c;
	}
	sort(ALL(p),cmp);
	rep(i,n-1)
	{
		if(p[i].c==p[i+1].c&&(p[i].t==p[i+1].s||p[i].t==p[i+1].s+1))
		{
			p[i].t = p[i+1].t;
			p[i+1].t = 200008;
			p[i+1].s = 200008;
		}
	}
	int aa = p[n-1].c;
	rep(i,n)
	{
		imos[p[i].s]++;
		imos[p[i].t+1]--;
	}
	rep(i,150005)
	{
		imos[i+1] += imos[i];
	}
	int ans = 0;
	rep(i,150007)
	{
		ans = max(imos[i],ans);
	}
	cout<<min(c,ans)<<endl;
	return 0;
}
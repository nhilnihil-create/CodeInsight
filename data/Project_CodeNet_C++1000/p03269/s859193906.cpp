#include <bits/stdc++.h>

#ifdef NON_SUBMIT
#define TEST(n) (n)
#else
#define TEST(n) ((void)0)
#endif

using namespace std;

int dist[20];
vector<tuple<int,int,int>> E;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	TEST(freopen("input.txt", "r", stdin));
	TEST(freopen("output.txt", "w", stdout));
	TEST(freopen("debug.txt", "w", stderr));
	int L, m=20, c, a, b, w;
	cin>>L;
	for(int i=18;i>0;i--) {
		if(((1<<(18-i))|dist[i+1])>=L) break;
		dist[m=i]=(1<<(18-i))|dist[i+1];
		E.emplace_back(i+1,i+2,0);
		E.emplace_back(i+1,i+2,1<<(18-i));
	}
	E.emplace_back(1,m+1,0);
	c=dist[m]+1;
	for(int i=m;i<20;i++) if(dist[i]+c<L) {
		E.emplace_back(1,i+1,c);
		c+=dist[i--]+1;
	}
	cout<<20<<' '<<E.size()<<'\n';
	for(auto e: E) {
		tie(a,b,w)=e;
		cout<<a<<' '<<b<<' '<<w<<'\n';
	}
	return 0;
}
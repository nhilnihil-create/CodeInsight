#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<cmath>
#include<map>
using namespace std;
typedef long long LL;
const int N = 1e5+10;
inline LL read()
{
	register LL x = 0 , f = 0; register char c = getchar();
	while(c < '0' || c > '9') f |= c == '-' , c = getchar();
	while(c >= '0' && c <= '9') x = (x << 3) + (x << 1) + c - '0' , c = getchar();
	return f ? -x : x;
}
int n;
LL d[N];
int eu[N] , ev[N] , siz[N];
vector<int> G[N];
map<LL , int> mp;
struct node
{
	LL d;
	int id;
}p[N];

inline bool cmp(const node &A , const node &B) { return A.d > B.d; }

void dfs1(int x , int dep , int rot)
{
	siz[x] = 1; d[rot] += dep;
	for(int i = 0 ; i < G[x].size() ; ++i) dfs1(G[x][i] , dep + 1 , rot) , siz[x] += siz[G[x][i]];
	return ;
}

void dfs2(int x)
{
	for(int i = 0 ; i < G[x].size() ; ++i)
	{
		d[G[x][i]] = d[x] + n - 2 * siz[G[x][i]];
		dfs2(G[x][i]);
	}
	return ;
}

int main()
{
	n = read();
	for(int i = 1 ; i <= n ; ++i) p[i].d = read() , p[i].id = i , mp[p[i].d] = i;
	LL sum = 0;
	for(int i = 1 ; i <= n ; ++i) sum += p[i].d;
	if(sum & 1) { puts("-1"); return 0; }
	sort(p + 1 , p + 1 + n , cmp);
	for(int i = 1 ; i <= n ; ++i) siz[i] = 1;
	for(int i = 1 ; i <  n ; ++i)
	{
		LL fa_d = p[i].d - n + 2 * siz[p[i].id];
		if(!mp.count(fa_d)) { puts("-1"); return 0; }
		ev[i] = p[i].id; eu[i] = mp[fa_d]; siz[eu[i]] += siz[ev[i]];
	}
	for(int i = 1 ; i <  n ; ++i) G[eu[i]].push_back(ev[i]);
	dfs1(p[n].id , 0 , p[n].id); dfs2(p[n].id);
	for(int i = 1 ; i <= n ; ++i) if(d[p[i].id] != p[i].d) { puts("-1"); return 0; }
	for(int i = 1 ; i <  n ; ++i) cout << eu[i] << ' ' << ev[i] << '\n';
	return 0;
}
#include <iostream>
#include <vector>
#include <set>
using namespace std;
char s[200005];
vector<int> v[200005];
int cnt[200005][2];
struct cmp
{
	bool operator()(const int &a,const int &b) const
	{
		int ca=min(cnt[a][0],cnt[a][1]),cb=min(cnt[b][0],cnt[b][1]);
		if (ca==cb)
		return (a<b);
		return (ca<cb);
	}
};
set<int,cmp> st;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	getchar();
	scanf("%s",s);
	while (m--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		a--;
		b--;
		v[a].push_back(b);
		v[b].push_back(a);
		cnt[a][s[b]-'A']++;
		cnt[b][s[a]-'A']++;
	}
	for (int i=0;i<n;i++)
	st.insert(i);
	while (!st.empty())
	{
		int node=*st.begin();
		if (min(cnt[node][0],cnt[node][1]))
		break;
		st.erase(node);
		for (int u:v[node])
		{
			if (st.find(u)==st.end())
			continue;
			st.erase(u);
			cnt[u][s[node]-'A']--;
			st.insert(u);
		}
	}
	printf(st.empty()? "No":"Yes");
}
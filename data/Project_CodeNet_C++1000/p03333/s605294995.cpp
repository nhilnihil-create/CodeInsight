#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <utility>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <sstream>
#include <cstring>
#include <bitset>
#include <stack>
using namespace std;
#define MP make_pair
#define PB push_back
const int INF=1e9;

int n;
pair<int,int> p[100005];
bool del[100005];
priority_queue <pair<int,int> >q1,q2;
long long ans;

inline long long solve(int dir)
{
	int pos=0;
	memset(del,false,sizeof(del));
	long long res=0;
	while (!q1.empty()) q1.pop();
	while (!q2.empty()) q2.pop();
	for (int i=1;i<=n;i++)
	{
		q1.push(MP(p[i].first,i));
		q2.push(MP(-p[i].second,i));
	}
	while (true)
	{
		if (dir==0)
		{
			while (!q1.empty() && del[q1.top().second]) q1.pop();
			if (q1.empty()) break;
			int nxt=q1.top().second;
			if (p[nxt].first<=pos) break;
			del[nxt]=true;
			res+=(long long)(p[nxt].first-pos);
			pos=p[nxt].first;
		}
		else
		{
			while (!q2.empty() && del[q2.top().second]) q2.pop();
			if (q2.empty()) break;
			int nxt=q2.top().second;
			if (p[nxt].second>=pos) break;
			del[nxt]=true;
			res+=(long long)(pos-p[nxt].second);
			pos=p[nxt].second;
		}		
		dir=!dir;
	}
	return res+(long long)abs(pos);
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		p[i]=MP(x,y);
	}
	ans=solve(0);
	ans=max(ans,solve(1));
	cout<<ans;
	return 0;
}
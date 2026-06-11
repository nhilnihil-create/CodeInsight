#include<bits/stdc++.h>
using namespace std;

int k;
int num[100010],out = 100010; 
bool v[100010],l,l2;

void dfs()
{
	queue < int > q;
	q.push(0);
	v[0] = 0;
	while(!q.empty())
	{
		int now = q.front();
		if(now == 0)
		{
			if(l2 == 0) l2 = 1;
			else
			{
				out = min(out,num[now]);
				l = 1;
			}
		}
		if((num[(now + 1) % k] > num[now] + 1 || num[(now + 1) % k] == -1) && l == 0)
		{
			num[(now + 1) % k] = num[now] + 1;
			if(v[(now + 1) % k] == 0)
			q.push((now + 1) % k);
			v[(now + 1) % k] = 1;
		}
		if((num[now * 10 % k] > num[now] || num[now * 10 % k] == -1) && now * 10 % k != now && l == 0)
		{
			num[now * 10 % k] = num[now];
			if(v[now * 10 % k] == 0)
			q.push(now * 10 % k);
			v[now * 10 % k] = 1;
		}
		v[now] = 0;
		q.pop();
		l = 0;
		if(now == 0)
		num[now] = -1;
	}
}

int main()
{
	cin>>k;
	for(int i = 1;i <= k;i++)
	num[i] = -1;
	
	dfs();
	
	cout<<out;
	
	return 0;
}

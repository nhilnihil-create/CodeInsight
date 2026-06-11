#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MP make_pair
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define PLI pair<ll, int>
#define PIL pair<int, ll>
#define STR string
#define Fst first
#define Snd second
#define SHN 1e9
#define LSHN 1e18
using namespace std;
int dist[100010];
deque<int> dq;
int n;
int main()
{
	cin >>n;
	fill(dist,dist+n,1e9);
	dist[1]=1;
	dq.push_back(1),dq.push_back(1);
	while (1)
	{
		int x=dq.front(); dq.pop_front();
		int y=dq.front(); dq.pop_front();
		//cout <<x<<" "<<y<<" ###########\n"; 
		if (!x)
		{
			cout <<y;
			return 0;
		}
		if (dist[(x*10)%n]>y)
		{
			dist[(x*10)%n]=y;
			dq.push_front(y);
			dq.push_front((x*10)%n);
		}
		if (dist[(x+1)%n]>y+1)
		{
			dist[(x+1)%n]=y+1;
			dq.push_back((x+1)%n);
			dq.push_back(y+1);
		}
	}
	return 0;
} 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<stack>
#include<algorithm>
using namespace std;
const int N=2e5+10;
int n,a[N],L,R,ANS,MID;
map<int,int>cnt;
stack<pair<int,int> >st;
bool check(int nw)
{
	map<int,int>cnt;
	stack<pair<int,int> >st;
	if (nw==1){for (int i=2;i<=n;i++)if (a[i]<=a[i-1])return 0;return 1;}
	if (a[1]!=1) st.push(make_pair(1,1));
	for (int i=1;i<=n;i++)
	{	
		int t=0;
		while (!st.empty())
			if (a[i]<st.top().first) st.pop(),t=1;else break;
		int cur=a[i];
		if (!st.empty()){
			bool ok=0;
			while (!ok)
			{
				if (!st.size()) return 0;
				int x=st.top().first;
				if (x<cur) st.push(make_pair(cur,t+1)),ok=1;else
				{
					int y=st.top().second+1;
					if (y>nw) cur--,st.pop();			
					else st.pop(),st.push(make_pair(x,y)),ok=1;
					t=1;
				}
			}
		}else st.push(make_pair(1,1));
	}
	return 1;
}
int main()
{
	scanf("%d",&n);for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	L=1,R=n;
	while (L<R){MID=L+R>>1;if (check(MID)) R=MID;else L=MID+1;}
	cout<<R;
}
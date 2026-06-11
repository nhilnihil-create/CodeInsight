#include<iostream>
#include<deque>
using namespace std;

int k;
bool vis[200000];
pair<int,int>p;
deque<pair<int,int>>q;

int main()
{
	cin>>k;
	q.push_front(make_pair(1,0));
	while(q.size())
	{
		p=q.front();
		q.pop_front();
		if(vis[p.first])
			continue;
		vis[p.first]=1;
		if(p.first==0)
		{
			cout<<p.second+1;
			return 0;
		}
		q.push_back(make_pair((p.first+1)%k,p.second+1));
		q.push_front(make_pair((p.first*10)%k,p.second));
	}
}
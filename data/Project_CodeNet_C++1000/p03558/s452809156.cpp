#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
int n,m,k; 
deque <P> q;
int vis[100005];
int main()
{
	cin>>k;
	q.push_front(make_pair(1,1));
	while(!q.empty())
	{
		P top=q.front();
		//cout<<top.first<<" "<<top.second<<endl; 
		q.pop_front();
		if(vis[top.first]) continue;
        vis[top.first]=1;
		if(top.first==0)
		{
			cout<<top.second<<endl;
			return 0;
		}
		q.push_front(make_pair((top.first*10)%k,top.second));
		q.push_back(make_pair((top.first+1)%k,top.second+1));
	}
	return 0;
}
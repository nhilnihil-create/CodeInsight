#include<iostream>
#include<cstdio>
#include<cctype>
#include<queue> 
using namespace std;
#define mp make_pair
#define pii pair<int,int>
const int maxn=1e5+10;
int k;
int vis[maxn];
deque<pii> q;
inline int read()
{
	int x=0;bool f=0;char c=getchar();
	while(!isdigit(c)) {f|=c=='-';c=getchar();}
	while(isdigit(c)) {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f?-x:x;
}
int main()
{
	k=read();
	q.push_front(mp(1,1));
	while(!q.empty())
	{
		pii tmp=q.front();
		q.pop_front();
		int mod=tmp.first,ans=tmp.second;
		if(vis[mod]) continue;
		vis[mod]=1;
		if(!mod) {cout<<ans;return 0;}
		q.push_front(make_pair(((mod<<3)+(mod<<1))%k,ans));//乘10代价为0 
        q.push_back(make_pair((mod+1)%k,ans+1));//加1代价为1 
    }
}
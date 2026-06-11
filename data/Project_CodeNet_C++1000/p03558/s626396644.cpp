#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef pair<int,int> pi;
pi u;
deque<pi>q;
int k;
bool vis[100002];
int main(){
	scanf("%d",&k);
	q.push_front({1,1});
	while (1){
		u=q.front(),q.pop_front();
		if (vis[u.fi]) continue;
		vis[u.fi]=1;
		if (!u.fi) return printf("%d",u.se),0;
		q.push_front({u.fi*10%k,u.se});
		q.push_back({(u.fi+1)%k,u.se+1});
	}
}
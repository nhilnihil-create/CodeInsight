#include <bits/stdc++.h>
using namespace std;

deque<int> q;
int dis[100005];

int main() {
	int n;
	scanf("%d",&n);
	memset(dis,0x7f,sizeof(dis));
	dis[1]=1;
	q.push_back(1);
	while(!q.empty()) {
		int u=q.front();
		q.pop_front();
		if(dis[(u*10)%n]>dis[u]) {
			dis[(u*10)%n]=dis[u];
			q.push_front((u*10)%n);
		}
		if(dis[(u+1)%n]>dis[u]+1) {
			dis[(u+1)%n]=dis[u]+1;
			q.push_back((u+1)%n);
		}
	}
	printf("%d\n",dis[0]);
}
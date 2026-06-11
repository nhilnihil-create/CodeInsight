#include<bits/stdc++.h>
using namespace std;
deque<int>q;
int mn[100100],K;
int bfs(){
	memset(mn,0x3f3f3f3f,sizeof(mn));
	mn[1]=1,q.push_back(1);
	while(true){
		int x=q.front();q.pop_front();
		if(!x)return mn[x];
		if(mn[(x*10)%K]>mn[x])mn[(x*10)%K]=mn[x],q.push_front((x*10)%K);
		if(mn[(x+1)%K]>mn[x]+1)mn[(x+1)%K]=mn[x]+1,q.push_back((x+1)%K);
	}
}
int main(){
	scanf("%d",&K);
	printf("%d\n",bfs());
	return 0;
} 
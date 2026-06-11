#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9'){
		if (ch=='-') f=-1;
		ch=getchar();
	}
	while (ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^'0');
		ch=getchar();
	}
	return x*f;
}
int d[MAXN],vis[MAXN];
deque<int>Q;
inline void Push(int x,int pre,int len,bool flag){
	d[x]=min(d[x],d[pre]+len);
	if (flag) Q.push_front(x);
	else Q.push_back(x);
}
int main(){
	int K=read();
	memset(d,0x3f,sizeof(d));
	Q.push_front(1),d[1]=1;
	while (Q.size()){
		int x=Q.front();Q.pop_front();
		if (!vis[x]) vis[x]=true;
		else continue;
		if (!x){
			printf("%d\n",d[x]);
			return 0;
		}
		Push((x+1)%K,x,1,0);
		Push((x*10)%K,x,0,1);
	}
}
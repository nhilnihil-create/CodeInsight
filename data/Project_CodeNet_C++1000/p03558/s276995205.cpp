#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define MN 100005
using namespace std;
int n,f[MN];
deque<int> q;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)f[i]=1e9;f[1]=1;q.push_front(1);
	while(!q.empty()){
		int tmp=q.front();q.pop_front();
		if(f[tmp*10%n]>f[tmp])f[tmp*10%n]=f[tmp],q.push_front(tmp*10%n);
		if(f[(tmp+1)%n]>f[tmp]+1)f[(tmp+1)%n]=f[tmp]+1,q.push_back((tmp+1)%n);
	}printf("%d\n",f[0]);
}
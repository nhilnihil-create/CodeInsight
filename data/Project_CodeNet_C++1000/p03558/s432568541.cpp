#include<iostream>
#include<cstdio>
using namespace std;
typedef pair<int,int> P;
int d[101000];P q[201000];int H=100000,T=100000;
int h[101000],nxt[201000],K=0,to[201000],cost[201000];
void ins(int u,int v,int c){nxt[++K]=h[u];h[u]=K;to[K]=v;cost[K]=c;}
int main()
{
	int k;scanf("%d",&k);
	for(int i=0;i<k;i++)ins(i,i*10%k,0),ins(i,(i+1)%k,1);
	q[T++]=P(1,1);
	while(H<T)
	{
		P p=q[H++];int u=p.first;if(d[u])continue;d[u]=p.second;
		for(int i=h[u];i;i=nxt[i])if(!cost[i])q[--H]=P(to[i],d[u]);else q[T++]=P(to[i],d[u]+1);
	}
	printf("%d",d[0]);return 0;
}
//我们发现，在模k意义下同余的sum是等价的，只要保留答案最小的即可
//新建一个图，共 k 个节点，代表 模k 得到的值。
//建边的依据是已知一个数x%k=p，那么在 x 后面再加一位数得到 y ，可以知道 y%k 的值，于是就得到了一个图，每条边代表往后加一位，边权就是这一位的数字。
//跑一遍最短路，其中 d[i] 意义就是模 k 余 i 的数中每一位的和最少是多少，开始 1~9 都加入队列
//但是还可以优化
//我们是把a向(a*10+b)%k连一条边权为b的边
//画个图我们会发现，只要把a向a*10%k 连一条边权为0的边 和 (a+1)%k 连一条边权为1的边即可，这与原图是等价的
//这种连边可以理解为把这个数后面加一个0或者把这个数加1 
//跑01bfs即可 
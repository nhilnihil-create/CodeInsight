#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
const int MR=100010;


deque<int> q;
int d_min[MR];
int parent[MR];
int type[MR];
int main(){
	memset(d_min,-1,sizeof(d_min));
	d_min[1]=1;
	int K;
	cin>>K;
	q.push_back(1);
	while(1){
		int now=q.front();
		//printf("%d\n",now);
		if(now==0){
			printf("%d\n",d_min[now]);
			break;
		}
		q.pop_front();
		if(d_min[(now*10)%K]==-1 || d_min[(now*10)%K]>d_min[now]){
			q.push_front((now*10)%K);
			d_min[(now*10)%K]=d_min[now];
			parent[(now*10)%K]=now;
			type[(now*10)%K]=0;
		}
		if(d_min[(now+1)%K]==-1){
			q.push_back((now+1)%K);
			d_min[(now+1)%K]=d_min[now]+1;
			parent[(now+1)%K]=now;
			type[(now+1)%K]=1;
		}
	}
	return 0;
}
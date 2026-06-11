#include<bits/stdc++.h>
using namespace std;
const int maxn=200100;
char str[maxn];
int beg[maxn],tto[maxn<<1],nex[maxn<<1],e;
void putin(int s,int t){
	tto[++e]=t;
	nex[e]=beg[s];
	beg[s]=e;
}
int q[maxn],l,r;
bool inq[maxn];
int cntA[maxn],cntB[maxn];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	scanf("%s",str+1);
	int s,t;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&s,&t);
		putin(s,t);
		putin(t,s);
	}
	l=1,r=0;
	for(int i=1;i<=n;i++){
		for(int j=beg[i];j;j=nex[j]){
			if(str[tto[j]]=='A')
				cntA[i]++;
			else
				cntB[i]++;
		}
		if(cntA[i]==0||cntB[i]==0){
			q[++r]=i;
			inq[i]=1;
		}
	}
	int u;
	while(l<=r){
		u=q[l],l++;
		for(int i=beg[u];i;i=nex[i]){
			if(str[u]=='A')
				cntA[tto[i]]--;
			else
				cntB[tto[i]]--;
			if((cntA[tto[i]]==0||cntB[tto[i]]==0)&&!inq[tto[i]]){
				inq[tto[i]]=1;
				q[++r]=tto[i];
			}
		}
	}
	if(r<n)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}
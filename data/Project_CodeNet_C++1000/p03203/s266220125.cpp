#include <bits/stdc++.h>
using namespace std;
const int N=400010;
int i,j,k,n,m,x,y,t,la,no,ans;
struct data{int l,r,sum,lazy;}T[2][N*4];
vector<int>c[N];
void build(int id,int i,int l,int r){
	T[id][i]={l,r,0,0};
	if (l==r)return;
	int mid=l+r>>1;
	build(id,i*2,l,mid);build(id,i*2+1,mid+1,r);
}
void pushup(int id,int i){T[id][i].sum=T[id][i*2].sum+T[id][i*2+1].sum;}
void pushdown(int id,int i){
	if (T[id][i].lazy){
		T[id][i*2].lazy=T[id][i*2+1].lazy=T[id][i].lazy;
		T[id][i*2].sum=(T[id][i*2].r-T[id][i*2].l+1)*(T[id][i].lazy-1);
		T[id][i*2+1].sum=(T[id][i*2+1].r-T[id][i*2+1].l+1)*(T[id][i].lazy-1);
		T[id][i].lazy=0;
	}
}
void change(int id,int i,int l,int r,int num){
	pushdown(id,i);
	if (T[id][i].l==l&&T[id][i].r==r){
		T[id][i].sum=num*(r-l+1);
		T[id][i].lazy=num+1;
		return;
	}
	int mid=T[id][i].l+T[id][i].r>>1;
	if (r<=mid)change(id,i*2,l,r,num);
	else if (l>mid)change(id,i*2+1,l,r,num);
	else{change(id,i*2,l,mid,num);change(id,i*2+1,mid+1,r,num);}
	pushup(id,i);
}
int query(int id,int i,int l,int r){
	pushdown(id,i);
	if (T[id][i].sum==0)return -1;
	if (T[id][i].l==T[id][i].r)return T[id][i].l;
	int mid=T[id][i].l+T[id][i].r>>1;
	if (r<=mid)return query(id,i*2,l,r);
	else if (l>mid)return query(id,i*2+1,l,r);
	else {
		int te=query(id,i*2,l,mid);
		if (te!=-1)return te;
		return query(id,i*2+1,mid+1,r);
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&t);
	ans=1013687232;
	for (i=1;i<=t;i++){
		scanf("%d%d",&x,&y);
		if (x>1)c[y].push_back(x);
	}
	for (i=1;i<=m;i++)c[i].push_back(n+1);
	for (i=1;i<=m;i++)sort(c[i].begin(),c[i].end());
	no=0;la=1;
	build(0,1,1,n);build(1,1,1,n);
	change(no,1,1,c[1][0]-1,1);
	ans=c[1][0]-1;
	for (i=2;i<=m;i++){
		swap(no,la);change(no,1,1,n,0);
		int be=1;
		for (j=0;j<c[i].size();j++){
			if (be<=c[i][j]-2){
				int pos=query(la,1,be,c[i][j]-2);
				if (pos!=-1){change(no,1,pos+1,c[i][j]-1,1);/*printf("###%d %d %d\n",i,c[i][j],i-1+c[i][j]-2);*/ans=min(ans,c[i][j]-1);}
			}
			be=c[i][j];
		}
	}
	printf("%d\n",ans);
	return 0;
}
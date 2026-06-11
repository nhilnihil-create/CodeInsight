#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
struct Roa{
	int u,v,k;
};
vector<Roa>ans;
int n,m,lg[N];
void addedge(int u,int v,int k){
	Roa a;
	a.u=u,a.v=v,a.k=k;
	ans.push_back(a);
	m++;
}
int main(){
	int l;
	scanf("%d",&l);
	lg[1]=0;
	for (int i=2;i<=l;i++) lg[i]=lg[i>>1]+1;
	int p=lg[l]+1;
	n=p;
	for (int i=1;i<n;i++)
	addedge(i,i+1,0),addedge(i,i+1,(1<<(n-i-1)));
	int now=1<<(n-1);
	for (int i=n-1;i>=1;i--){
		if (l&(1<<(i-1))) addedge(1,n-i+1,now),now+=(1<<(i-1));
	}
	printf("%d %d\n",n,m);
	for (int i=0;i<ans.size();i++){
		int u=ans[i].u,v=ans[i].v,k=ans[i].k;
		printf("%d %d %d\n",u,v,k);
	}
	return 0;
}
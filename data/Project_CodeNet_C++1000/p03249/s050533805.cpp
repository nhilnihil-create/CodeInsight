#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=100100;
struct Node{
	LL d;
	LL td;
	int i,sz,fa;
	vector<int> ch;
	Node():td(0),sz(1){}
	bool operator<(const Node o)const{
		return d<o.d;
	}
};
Node d[N];
map<LL,int> fd;
void GG(){
	puts("-1");
	exit(0);
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&d[i].d);
		d[i].i=i;
	}
	sort(d+1,d+n+1);
	for(int i=1;i<=n;i++){
		fd[d[i].d]=i;
	}
	for(int i=n;i>1;i--){
		fd.erase(d[i].d);
		LL nd=d[i].d-(n-2*d[i].sz);
		if(!fd.count(nd)){
			GG();
		}
		int f=fd[nd];
		d[i].fa=d[f].i;
		d[f].sz+=d[i].sz;
		d[f].td+=d[i].td+d[i].sz;
	}
	if(d[1].td!=d[1].d){
		GG();
	}
	for(int i=2;i<=n;i++){
		printf("%d %d\n",d[i].fa,d[i].i);
	}
	return 0;
}
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+9;
struct node{
	int d,id;
	node(int d=0,int id=0):d(d),id(id){}
	friend bool operator<(node x,node y){
		return x.d<y.d;
	}
}d[maxn];
int n,dis,tot,siz[maxn],u[maxn],v[maxn];
signed main(){
	cin>>n;
	for(int i=1,x;i<=n;++i)cin>>x,d[i]=node(x,i),siz[i]=1;
	sort(d+1,d+1+n);
	for(int i=n;i>1;--i){//最大的一定是叶子 可以递推siz
		int nxt=d[i].d-n+2*siz[i];//下一个的d
		int p=lower_bound(d+1,d+1+n,node(nxt,0))-d;
		if(d[p].d!=nxt)return puts("-1"),0;//如果找不到 不符合
		u[++tot]=d[i].id;v[tot]=d[p].id;
		siz[p]+=siz[i];
		dis+=siz[i];
	}
	if(dis!=d[1].d)puts("-1");//因为只判断了d之差的关系 要看找出的siz是否符合条件
	else{
		for(int i=1;i<=tot;++i)cout<<u[i]<<" "<<v[i]<<endl;
	}
	return 0;
}
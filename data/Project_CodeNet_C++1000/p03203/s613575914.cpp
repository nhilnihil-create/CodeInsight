#include <bits/stdc++.h>
using namespace std;

const int maxn=2e5+10;
int h,w,n,ans=1e9;
vector<int> vec[maxn];
bool st[maxn<<2],tag[maxn<<2];

inline void push_up(int rt){
	st[rt]=st[rt<<1]|st[rt<<1|1];
}
inline void push_down(int rt){
	if(tag[rt]){
		tag[rt<<1]=tag[rt<<1|1]=true;
		st[rt<<1]=st[rt<<1|1]=true;
		tag[rt]=false;
	}
}
void modify0(int rt,int l,int r,int pos){
	if(l==r){
		st[rt]=false;
		return;
	}
	push_down(rt);
	int mid=l+r>>1;
	if(pos<=mid)
		modify0(rt<<1,l,mid,pos);
	else
		modify0(rt<<1|1,mid+1,r,pos);
	push_up(rt);
}
void modify1(int rt,int l,int r,int x,int y){
	if(l==x&&r==y){
		st[rt]=true;
		tag[rt]=true;
		return;
	}
	push_down(rt);
	int mid=l+r>>1;
	if(y<=mid)
		modify1(rt<<1,l,mid,x,y);
	else if(x>mid)
		modify1(rt<<1|1,mid+1,r,x,y);
	else{
		modify1(rt<<1,l,mid,x,mid);
		modify1(rt<<1|1,mid+1,r,mid+1,y);
	}
	push_up(rt);
}
int query(int rt,int l,int r,int x,int y){
	if(!st[rt])
		return -1;
	if(l==r)
		return l;
	push_down(rt);
	int mid=l+r>>1;
	if(y<=mid)
		return query(rt<<1,l,mid,x,y);
	else if(x>mid)
		return query(rt<<1|1,mid+1,r,x,y);
	else{
		int tmp=query(rt<<1,l,mid,x,mid);
		if(~tmp)
			return tmp;
		else
			return query(rt<<1|1,mid+1,r,mid+1,y);
	}
}

int main(){
	scanf("%d%d%d",&h,&w,&n);
	while(n--){
		int x,y;
		scanf("%d%d",&x,&y);
		vec[y].push_back(x);
	}
	modify1(1,1,h,1,1);
	for(int i=1;i<=w;++i){
		sort(vec[i].begin(),vec[i].end());
		for(int j=0;j<vec[i].size();++j)
			modify0(1,1,h,vec[i][j]);
		vec[i].push_back(h+1);
		for(int j=0,last=0;j<vec[i].size();last=vec[i][j],++j){
			if(last==vec[i][j]-1)
				continue;
			int pos=query(1,1,h,last+1,vec[i][j]-1);
			if(~pos){
				modify0(1,1,h,pos);
				if(pos!=vec[i][j]-1)
					modify1(1,1,h,pos+1,vec[i][j]-1);
				ans=min(ans,vec[i][j]-1);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
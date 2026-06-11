//01:20
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+10;
struct T
{
	int v,id;
	bool operator<(T b)const 
	{return v<b.v;}
};
struct T1
{
	int v,id;
	bool operator<(T1 b)const 
	{return v>b.v;}
};
priority_queue<T>L;
priority_queue<T1>R;
bool vis[N];
struct G
{
	int l,r;
	bool In(int v)
	{
		if(l<=v&&v<=r)return true;
		else return false;
	}
}D[N];
int main()
{
	//freopen("/home/zz7/CFInput","r",stdin);
	int n;scanf("%d",&n);
	int a=0,b=0;
	for(int i=0;i<n;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		D[i]={l,r};
		T g={l,i};T1 g1={r,i};
		L.push(g);R.push(g1);
		if(l>0)a++;
		else if(r<0)b++;
	}
	int flag=0,ins=0;ll ans=0;
	if(a<b)flag=1;
	for(int i=0;i<2*n;i++){
		if(flag==1){
			//min
			T1 p=R.top();R.pop();
			if(vis[p.id])continue;
			vis[p.id]=true;
			if(!D[p.id].In(ins)){
				ans+=abs(ins-p.v);
				ins=p.v;
			}
		}else {
			//max
			T p=L.top();L.pop();
			if(vis[p.id])continue;
			vis[p.id]=true;
			if(!D[p.id].In(ins)){
				ans+=abs(ins-p.v);
				ins=p.v;
			}
		}flag=!flag;
	}cout<<ans+abs(ins)<<'\n';
}

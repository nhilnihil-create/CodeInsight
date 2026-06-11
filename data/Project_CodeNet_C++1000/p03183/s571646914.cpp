#include<bits/stdc++.h>
#define ll long long
#define re register
using namespace std;
const int maxn=1e4+10;
const int maxw=2e4+10;
template<typename T> void read(T &x){
	T f=1;x=0;
	char c=getchar();
	while(c<'0' || c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0' && c<='9'){x=(x<<3)+(x<<1)+c-48;c=getchar();}
	x*=f;
}
int n;
struct node {
	ll w,s,v,tw;
}t[maxn];
bool cmp(node a,node b){
	return a.tw<b.tw;
}
ll f[maxw],ans;
int main(){
	read(n);
	for(re int i=1;i<=n;i++){
		read(t[i].w);read(t[i].s);read(t[i].v);                                                                                                                                 
		t[i].tw=t[i].w+t[i].s;
	}
	sort(t+1,t+n+1,cmp);
	for(re int i=1;i<=n;i++){
		for(re int j=maxw-5;j>=t[i].w;j--){
			if(t[i].tw>=j){
				f[j]=max(f[j],f[j-t[i].w]+t[i].v);
			}
		}
	}
	for(re int i=0;i<=maxw-5;i++){
		ans=max(ans,f[i]);
	}
	cout<<ans<<endl;
	return 0;
}

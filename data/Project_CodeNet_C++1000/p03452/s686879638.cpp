#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int read(){
	int x=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1; ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
int f[N],d[N];
int find(int x){
	if (x==f[x]) return x;
	int fa=find(f[x]);
	d[x]=d[x]+d[f[x]];
	return f[x]=fa;
}
int main(){
	int n=read(),m=read();
	for (int i=1;i<=n;i++){
		d[i]=0; f[i]=i;
	}
	bool pd=0;
	while (m--){
		int l=read(),r=read(),v=read();
		int fl=find(l),fr=find(r);
		if (fl==fr){
			if (d[l]-d[r]!=v) pd=1;
		}else{
			f[fl]=fr;
			d[fl]=v+d[r]-d[l];
		}
	}
	if (pd==1) printf("No\n");
	else printf("Yes\n");
	return 0;
}
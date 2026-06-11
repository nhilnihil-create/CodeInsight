#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int read(){
	int x=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1; ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
int a[N],b[N][2],c[555];
bool cmp(int x,int y){
	return a[x]<a[y];
}
int main(){
	int n=read();
	int s=1<<n; a[s]=-1;
	for (int i=0;i<s;i++) a[i]=read();
	b[0][0]=0; b[0][1]=s;
	for (int i=1;i<s;i++){
		b[i][0]=i; b[i][1]=s;
		for (int j=0;j<n;j++){
			if (i&(1<<j)){
				int x=i^(1<<j);
				c[0]=b[i][0],c[1]=b[i][1],c[2]=b[x][1],c[3]=b[x][0];
				sort(c,c+4,cmp);
				b[i][0]=c[3]; if (c[3]==c[2]) b[i][1]=c[1]; else b[i][1]=c[2];
			}
		}
	}
	int ans=0;
	for (int i=1;i<s;i++){
		ans=max(ans,a[b[i][0]]+a[b[i][1]]);
		printf("%d\n",ans);
	}
	return 0;
}
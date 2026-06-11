#include<bits/stdc++.h>
using namespace std;
int read(){
	int rt=0;char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){rt=rt*10+ch-'0';ch=getchar();}
	return rt;
}
int n,a[1<<18];
struct _{
	int v[2];
}data[1<<18];
bool cmp(int x,int y){
	return a[x]<a[y];
}
_ Merge(_ x,_ y){
	_ ret;
	ret.v[0]=ret.v[1]=-1;
	int buf[5],tot=0;
	for(int i=0;i<2;i++)
		if(x.v[i]!=-1){
			buf[++tot]=x.v[i];
		}
	for(int i=0;i<2;i++){
		if(y.v[i]!=-1){
			buf[++tot]=y.v[i];
		}
	}
	sort(buf+1,buf+1+tot);
	tot=unique(buf+1,buf+1+tot)-buf-1;
	sort(buf+1,buf+1+tot,cmp);
	for(int i=0;i<2;i++){
		if(tot>0){
			ret.v[i]=buf[tot--];
		}
	}
	return ret;
}
int main(){
	n=read();
	int m=n;
	n=(1<<n);
	for(int i=0;i<n;i++){
		a[i]=read();
		data[i].v[0]=i;
		data[i].v[1]=-1;
	}
	for(int i=0;i<m;i++){
		for(int j=n-1;j>=0;j--){
			if(j&(1<<i)){
				data[j]=Merge(data[j],data[j^(1<<i)]);	
			}
		//	cout<<data[j].v[0]<<" "<<data[j].v[1]<<" "<<i<<" "<<j<<endl;
		}
	}
	int ans = 0;
	for(int i=1;i<n;i++){
		
		if(data[i].v[0]+1 && data[i].v[1]+1){
			ans = max(ans,a[data[i].v[0]]+a[data[i].v[1]]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
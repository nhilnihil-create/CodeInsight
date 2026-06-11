#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
#include<cstdlib>
#define LL long long
#define LD long double
using namespace std;
const int NN=200000 +117;
const int MM=200000 +117;
int read(){
	int fl=1,x;char c;
	for(c=getchar();(c<'0'||c>'9')&&c!='-';c=getchar());
	if(c=='-'){fl=-1;c=getchar();}
	for(x=0;c>='0'&&c<='9';c=getchar())
		x=(x<<3)+(x<<1)+c-'0';
	return x*fl;
}
void open(){
	freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
}
void close(){
	fclose(stdin);
	fclose(stdout);
}


int m,n;
int a[NN]={};
struct node{
	int p,v;
}s[NN]={};
bool chk(int x){
	int top=0;
	for(int i=1;i<=n;++i){
		if(a[i]<=a[i-1]){
			int now=a[i];
			while(top&&s[top-1].p>now)--top;
			bool fl=1;
			while(top&&s[top-1].p==now){
				++s[top-1].v;
				if(s[top-1].v<x){
					fl=0;
					break;
				}
				--top;
				--now;
			}
			if(fl){
				if(now==0)return false;
				s[top].p=now;
				s[top].v=1;
				++top;
			}
		}
	}
	return true;
}
int main(){
	//open();
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	bool fl=0;
	for(int i=2;i<=n;++i){
		if(a[i]<=a[i-1]){
			fl=1;
		}
	}
	if(!fl){
		printf("1\n");
		return 0;
	}
	int l=2;
	int r=n;
	while(l!=r){
		int mid=(l+r)>>1;
		if(chk(mid)){
			r=mid;
		}
		else l=mid+1;
	}
	printf("%d\n",l);
	close();
	return 0;
}
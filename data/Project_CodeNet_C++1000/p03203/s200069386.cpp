#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL read(){
	LL x=0,f=0;
	char ch=getchar();
	while (!isdigit(ch))
		f|=ch=='-',ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?-x:x;
}
const int N=200005;
int h,w;
LL tmp=1e9+7;
unordered_map <LL,int> Map;
int Min[N];
int main(){
	Map.clear();
	h=read(),w=read();
	int n=read();
	for (int i=1;i<=h;i++){
		Min[i]=w+1;
		Map[tmp*i+w+1]=1;
	}
	while (n--){
		int x=read(),y=read();
		Map[tmp*x+y]=1;
		Min[x]=min(Min[x],y);
	}
	int x=1,y=1;
	while (1){
		x++;
		if (!Map[tmp*x+y+1])
			y++;
		if (Min[x]<=y){
			printf("%d\n",x-1);
			return 0;
		}
	}
	return 0;
}

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#include <bits/stdc++.h>
using namespace std;
template<class t> inline t read(t &x){
	char c=getchar();bool f=0;x=0;
	while(!isdigit(c)) f|=c=='-',c=getchar();
	while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
	if(f) x=-x;return x;
}
template<class t,class ...A> inline void read(t &x,A &...a){
	read(x);read(a...);
}
template<class t> inline void write(t x){
	if(x<0) putchar('-'),write(-x);
	else{if(x>9) write(x/10);putchar('0'+x%10);}
}

char s[15];
int n,x,y,z,ans;

signed main(){
	read(n);
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		if(s[1]=='B') y++;
		if(s[strlen(s+1)]=='A') x++;
		if(s[1]=='B'&&s[strlen(s+1)]=='A') z++;
		for(int i=2;s[i];i++) if(s[i-1]=='A'&&s[i]=='B') ans++;
	}
	x-=z;y-=z;
	if(z) ans+=z-1;
	if(x&&z) x--,ans++;
	if(y&&z) y--,ans++;
	ans+=min(x,y);
	write(ans);
}
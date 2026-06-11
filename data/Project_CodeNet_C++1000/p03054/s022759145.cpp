


#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int H,W,n,sx,sy;
char s[N],t[N];
int nw,mx;
int main(){
	//freopen("a.in","r",stdin);
	scanf("%d%d%d%d%d%s%s",&H,&W,&n,&sx,&sy,s+1,t+1);bool flg=1;
	nw=sy;mx=H+1;for(int i=1;i<=n;i++){if(s[i]=='L')nw--;mx=min(mx,nw);if(t[i]=='R'&&nw<W)nw++;}if(mx<1)flg=0;
	nw=sy;mx=0;for(int i=1;i<=n;i++){if(s[i]=='R')nw++;mx=max(mx,nw);if(t[i]=='L'&&nw>1)nw--;}if(mx>W)flg=0;
	nw=sx;mx=W+1;for(int i=1;i<=n;i++){if(s[i]=='U')nw--;mx=min(mx,nw);if(t[i]=='D'&&nw<H)nw++;}if(mx<1)flg=0;
	nw=sx;mx=0;for(int i=1;i<=n;i++){if(s[i]=='D')nw++;mx=max(mx,nw);if(t[i]=='U'&&nw>1)nw--;}if(mx>H)flg=0;
	if(!flg)puts("NO");else puts("YES");
}
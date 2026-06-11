#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,m,len;
int sx,sy;
char a[maxn];
char b[maxn];
int main(){
	scanf("%d%d%d%d%d",&n,&m,&len,&sx,&sy);
	scanf("%s",a+1);
	scanf("%s",b+1);
	int posx; int posy;
	posx=sx;
	for(int i=1;i<=len;i++){
		if(a[i]=='U') posx--;
		if(!posx){
			printf("NO\n");
			return 0;
		}else if(b[i]=='D'&&posx+1<=n) posx++;
	}
	posx=sx;
	for(int i=1;i<=len;i++){
		if(a[i]=='D') posx++;
		if(posx>n){
			printf("NO\n");
			return 0;
		}else if(b[i]=='U'&&posx-1>=1) posx--;
	}
	posy=sy;
	for(int i=1;i<=len;i++){
		if(a[i]=='L') posy--;
		if(!posy){
			printf("NO\n");
			return 0;
		}else if(b[i]=='R'&&posy+1<=m) posy++;
	}
	posy=sy;
	for(int i=1;i<=len;i++){
		if(a[i]=='R') posy++;
		if(posy>m){
			printf("NO\n");
			return 0;
		}else if(b[i]=='L'&&posy-1>=1) posy--;
	}
	printf("YES\n");
	return 0;
}
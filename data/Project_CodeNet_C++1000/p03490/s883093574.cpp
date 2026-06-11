#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

char s[10005];
int state,i,cnt;
bool tmpx[20005],tmpy[20005],*x=tmpx+10000,*y=tmpy+10000;
int v[20005],siz;
int main(){
	int ex,ey; scanf("%s %d %d",s,&ex,&ey);
	int N=strlen(s);
	s[N]='T';
	while(s[i]=='F') i++;
	x[i]=y[0]=1; 
	for(;s[i];i++){
		if(s[i]=='T') {
			siz=0;
			for(int j=-i;j<=i;j++){
				if(!state && x[j]){
					v[siz++]=j-cnt;
					v[siz++]=j+cnt;
					x[j]=0;
				} 
				else if(state && y[j]){
					v[siz++]=j-cnt;
					v[siz++]=j+cnt;
					y[j]=0;
				}
			}
			for(int j=0;j<siz;j++)
				if(!state) x[v[j]]=1;
				else y[v[j]]=1;
			cnt=0;
			state^=1;
		}
		else{
			cnt++;
		}
	}
	if(x[ex] && y[ey]) puts("Yes");
	else puts("No");
}
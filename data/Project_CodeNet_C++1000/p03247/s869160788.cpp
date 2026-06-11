#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<deque>
#include<stack>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<stdlib.h>
#include<cassert>
#include<time.h>
#include<bitset>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
const long long d2=(mod+1)/2;
const long double EPS=1e-9;
const long double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
long double ABS(long double a){return max(a,-a);}
int x[1100];
int y[1100];
bool v[1100];
bool h[1100];
char in[1100];
void calc(int X,int Y,int c){
	if(c<0)return;
	//printf("%d %d %d\n",X,Y,c);
	int len=1<<(max(0,c-1));
	if(X>=len){
		calc(X-len,Y,c-1);
		in[c]='R';
	}else if(Y>=len){
		calc(X,Y-len,c-1);
		in[c]='U';
	}else if(X>Y){
		calc(len-X,Y,c-1);
		for(int i=0;i<c;i++){
			if(in[i]=='L')in[i]='R';
			else if(in[i]=='R')in[i]='L';
		}
		in[c]='R';
	}else{
		calc(X,len-Y,c-1);
		for(int i=0;i<c;i++){
			if(in[i]=='U')in[i]='D';
			else if(in[i]=='D')in[i]='U';
		}
		in[c]='U';
	}
}
int main(){
	int a;scanf("%d",&a);
	for(int i=0;i<a;i++){
		scanf("%d%d",x+i,y+i);
	}
	int V=ABS(x[0]+y[0])%2;
	for(int i=1;i<a;i++){
		if(V!=ABS(x[i]+y[i])%2){
			printf("-1\n");return 0;
		}
	}
	for(int i=0;i<a;i++)x[i]-=V;
	for(int i=0;i<a;i++){
		if(x[i]<0){
			h[i]=true;
			x[i]*=-1;
		}
		if(y[i]<0){
			v[i]=true;
			y[i]*=-1;
		}
	}
	printf("%d\n",32+V);
	if(V)printf("1 ");
	for(int i=0;i<32;i++){
		if(i)printf(" ");
		printf("%d",1<<(max(0,i-1)));
	}
	printf("\n");
	for(int i=0;i<a;i++){
		calc(x[i],y[i],31);
		if(V)printf("R");
		for(int j=0;j<32;j++){
			if(h[i]){
				if(in[j]=='L')in[j]='R';
				else if(in[j]=='R')in[j]='L';
			}
			if(v[i]){
				if(in[j]=='U')in[j]='D';
				else if(in[j]=='D')in[j]='U';
			}
		}
		printf("%s\n",in);
	}
}
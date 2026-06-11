#include<bits/stdc++.h>
#define rep(X,A,B) for(int X=A;X<=B;X++)
#define tep(X,A,B) for(int X=A;X>=B;X--)
#define LL long long
#define DB double
const int N=200010;
using namespace std;

char s[N];
int n;
int cnt=0,u[N],v[N];

void ADD(int x,int y){
	cnt++;u[cnt]=x;v[cnt]=y;
}

int CHK(){
	if(s[1]=='0'||s[n]=='1')return 0;
	rep(i,1,n-1){
		if(s[i]!=s[n-i])return 0;
	}
	return 1;
}

void SOLVE(){
	int pos=1,tot=1;
	rep(sz,1,n-1){
		if(s[sz]=='1'){
			tot++;
			ADD(pos,tot);
			pos=tot;
		}
		else{
			tot++;
			ADD(pos,tot);
		}
	}
	rep(i,1,cnt)printf("%d %d\n",u[i],v[i]);
}

int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	if(CHK()==0){
		printf("-1\n");
		return 0;
	}
	SOLVE();
	return 0;
}
#include<bits/stdc++.h>
#define rep(X,A,B) for(int X=A;X<=B;X++)
#define tep(X,A,B) for(int X=A;X>=B;X--)
#define pb push_back
#define LL long long
const int N=300010;
using namespace std;

int n,m;

struct nn{
	int pos,val;
};

int cmp(nn A,nn B){
	return A.val>B.val;
}

nn hlp[6];
nn mx[2][N];

void READ(){
	scanf("%d",&m);
	n=(1<<m)-1;
	rep(i,0,n){
		scanf("%d",&mx[0][i].val);
		mx[0][i].pos=mx[1][i].pos=i;
		mx[1][i].val=0;
	}
}

void CHK(int x,int y){
	hlp[1]=mx[0][x];hlp[2]=mx[1][x];hlp[3]=mx[0][y];hlp[4]=mx[1][y];
	sort(hlp+1,hlp+4+1,cmp);
	mx[0][x]=hlp[1];
	rep(i,2,4){
		if(hlp[i].pos!=hlp[1].pos){
			mx[1][x]=hlp[i];
			return;
		}
	}
}

void INIT(){
	rep(i,0,n){
		rep(j,0,m-1){
			if(!(i&(1<<j)))continue;
			CHK(i,i^(1<<j));
		}
	}
}

int GET(int x){
	int ans=mx[0][x].val+mx[1][x].val;
	int flp=0;
	tep(i,m-1,1){
		if(!(x&(1<<i)))continue;
		int now=(flp|((1<<i)-1));
		ans=max(ans,mx[0][now].val+mx[1][now].val);
		flp|=(1<<i);
	}
	return ans;
}

int main(){
	READ();
	INIT();
	rep(i,1,n)printf("%d\n",GET(i));
	return 0;
}
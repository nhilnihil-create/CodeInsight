#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
template<typename T> void read(T &num){
	char c=getchar();T f=1;num=0;
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){num=(num<<3)+(num<<1)+(c^48);c=getchar();}
	num*=f;
}
template<typename T> void qwq(T x){
	if(x>9)qwq(x/10);
	putchar(x%10+'0');
}
template<typename T> void write(T x){
	if(x<0){x=-x;putchar('-');}
	qwq(x);putchar('\n');
}
int ans[20010];int s[5];

int main(){
	int n;read(n);
	if(n==3){cout<<"2 5 63"<<endl;return 0;}
	int t=n/8;int l=0;
	s[1]=2;s[2]=3;s[3]=4;s[4]=6;
	rep(i,1,t){
		rep(j,1,4){ans[++l]=s[j];s[j]+=6;}
		rep(j,1,4){ans[++l]=s[j];s[j]+=6;}
	}
	
	if(n%8==1){ans[++l]=s[4];}
	else if(n%8==2){ans[++l]=s[1];ans[++l]=s[3];}
	else if(n%8==3){ans[++l]=s[1];ans[++l]=s[3];ans[++l]=s[4];}
	else if(n%8==4){ans[++l]=s[1];ans[++l]=s[2];ans[++l]=s[3];ans[++l]=s[2]+6;}
	else if(n%8==5){
		ans[++l]=s[1];ans[++l]=s[2];ans[++l]=s[3];ans[++l]=s[4];ans[++l]=s[2]+6;
	}else if(n%8==6){
		rep(j,1,3){ans[++l]=s[j];s[j]+=6;}
		rep(j,1,3)ans[++l]=s[j];
	}else if(n%8==7){
		rep(j,1,4){ans[++l]=s[j];s[j]+=6;}
		rep(j,1,3)ans[++l]=s[j];
	}
	rep(i,1,n){qwq(ans[i]);putchar((i==n)?'\n':' ');}
	return 0;
}
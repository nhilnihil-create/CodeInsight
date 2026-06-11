#include<bits/stdc++.h>
#define rep(i,x,y) for (int i=(x); i<=(y); i++)
#define per(i,x,y) for (int i=(x); i>=(y); i--)
#define ll long long
#define N 300010
using namespace std;
int n,a,b,now,t1,t2,k1,k2,d[N];
int main(){
	bool flag=0;
	scanf("%d%d%d",&n,&a,&b);
	//a上升,b下降
	per (i,b,1) d[b-i+1]=i;
	a--; now=b;
	if (a){
		t1=(n-b)/a+1; k1=(n-b)%a;// printf("t1=%d,k1=%d\n",t1,k1);
		t2=(n-b)/a; k2=a-(n-b)%a;// printf("t1=%d,k1=%d\n",t1,k1);
		if (k1 && t1>b || k2 && t2>b){ puts("-1"); return 0; }
		if (((bool)t1)*k1+((bool)t2)*k2<a){ puts("-1"); return 0; }
		rep (t,1,k1){//now+t1--->now+1
			rep (i,1,t1) d[now+i]=now+t1-i+1;
			now+=t1;
		}
		rep (t,1,k2){
			rep (i,1,t2) d[now+i]=now+t2-i+1;
			now+=t2;
		}
	}
	rep (i,1,n) printf("%d ",d[i]);
	return 0;
}
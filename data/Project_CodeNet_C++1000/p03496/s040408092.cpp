#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#define MAXN 100

typedef long long ll;

const int INF=0x7fffffff;

using namespace std;

int n;

struct ANS{
	int x,y;
}ans[2*MAXN];
int tot=0;//次数

ll a[MAXN];

void front_back(){
	for(int i=2;i<=n;i++){ //从前往后看 
		if(a[i]<a[i-1]){
			a[i]+=a[i-1];
			tot++;
			ans[tot].x=i-1;//把i-1加到i上 
			ans[tot].y=i;
		}
	}
} 

void back_front(){//从后往前
	for(int i=n-1;i>=1;i--){//从后往前看 
		if(a[i]>a[i+1]){
			a[i]+=a[i+1];
			tot++;
			ans[tot].x=i+1;
			ans[tot].y=i;
		} 
	}
}



int main() {
	scanf("%d",&n);
	scanf("%lld",&a[1]);
	bool f=1;
	ll mx=a[1],mn=a[1];
	int sitmx=1,sitmn=1;
	for(int i=2;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]<a[i-1]&&f){//如果后面的更小则不满足条件 
			f=0;
		}
		if(a[i]>mx){//找最大值 及位置 
			mx=a[i];
			sitmx=i;
		}
		if(a[i]<mn){//找最小值 及位置 
			mn=a[i];
			sitmn=i;
		}
	}
	if(f){//已经满足条件 
		printf("0");
		return 0;
	}
	 
	if(mn>=0){//非负数 
		front_back();
	} 
	else if(mx<=0){//非正数 
		back_front();
	}
	else if(abs(mx)>abs(mn)){//最大值的绝对值更大 
		for(int i=1;i<=n;i++){//全部成为非负数 
			a[i]+=mx;
			tot++;
			ans[tot].x=sitmx;
			ans[tot].y=i;
		}
		front_back();
	}
	else {
		for(int i=1;i<=n;i++){//全部成为非正数 
			a[i]+=mn;
			tot++;
			ans[tot].x=sitmn;
			ans[tot].y=i;
		}
		back_front();
	}
	printf("%d\n",tot);
	for(int i=1;i<=tot;i++){
		printf("%d %d\n",ans[i].x,ans[i].y);
	}
//	for(int i=1;i<=n;i++){
//		printf("%lld ",a[i]);
//	}
	return 0;
}
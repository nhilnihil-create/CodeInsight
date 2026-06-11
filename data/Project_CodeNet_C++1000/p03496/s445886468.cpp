#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
#include<set>
#include<numeric>
#include<map>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i = 0;i<((int)(n));i++)
#define reg(i,a,b) for(int i = ((int)(a));i<=((int)(b));i++)
#define irep(i,n) for(int i = ((int)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(int i = ((int)(b));i>=((int)(a));i--)
typedef long long ll;
typedef pair<ll, ll> mp;

int main(void){
	int N,a[52],p=0,m=0,max=1;
	scanf("%d",&N);
	reg(i,1,N){
		scanf("%d",&a[i]);
		if(a[i]>0){
			p++;
		}else if(a[i]<0){
			m++;
		}
		if(abs(a[max])<abs(a[i]))max=i;
	}
	if(p==0 && m==0){//全て0
		printf("0\n");
	}else if(p==N){//全て正
		printf("%d\n",N-1);
		reg(i,1,N-1){
			printf("%d %d\n",i,i+1);
		}
	}else if(m==N){//全て負
		printf("%d\n",N-1);
		ireg(i,2,N){
			printf("%d %d\n",i,i-1);
		}
	}else{//その他
		//絶対値maxを足す
		printf("%d\n",2*(N-1));
		reg(i,1,N){
			if(i==max)continue;
			printf("%d %d\n",max,i);
		}
		if(a[max]>0){
			reg(i,1,N-1){
				printf("%d %d\n",i,i+1);
			}
		}else{
			ireg(i,2,N){
				printf("%d %d\n",i,i-1);
			}
		}
	}
	return 0;
}
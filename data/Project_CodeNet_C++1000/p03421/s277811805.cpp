// by Balloons
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() puts("okkkkkkkk")
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;

const int inf = 1e9;

int main(){
	int n,a,b;
	scanf("%d%d%d",&n,&a,&b);
	int low = (n-1)/a + 1,high = n-a+1;
	if(b < low || b > high)return puts("-1"),0;
	int cl=0,nc=n;
	for(int i=1;i<=n;i+=a){
		int na = i+a;
		if(nc-a+1 >= b){
			for(int j=nc-a+1;j<=nc;j++)printf("%d ",j);
			-- b;
			nc -= a;
		}else{
			for(int j=b;j<=nc;j++)printf("%d ",j);
			if(--b)for(int j=b;j>=1;j--)printf("%d ",j);
			break; 
		}
	}
	puts("");

	return 0;
}

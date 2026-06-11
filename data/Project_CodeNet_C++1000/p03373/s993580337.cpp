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
	int a,b,c,x,y;
	scanf("%d%d%d%d%d",&a,&b,&c,&x,&y);
	int per=min(2*c,a+b);
	int mi=min(x,y),mx=x+y-mi;
	int p=a;if(y==mx)p=b;
	printf("%lld\n",mi*per+min((mx-mi)*2*c,(mx-mi)*p));

	return 0;
}

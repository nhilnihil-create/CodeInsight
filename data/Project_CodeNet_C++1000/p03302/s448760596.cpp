//write：Sakura
//id：
//problem：
//note：

#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

typedef long long ll;

int a,b;
int ans1=0,ans2=0;

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d %d",&a,&b);
	ans1=a+b;
	ans2=a*b;
	if(ans1==15){
		puts("+");
		exit(0);
	}
	if(ans2==15){
		puts("*");
		exit(0);
	}
	else{
		puts("x");
		exit(0);
	}
	return 0;
}

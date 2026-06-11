#include<cstdio>
#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<cstring>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long LL;

const int maxn=1e6+7;
char a[maxn];

int main (){
	int a,b;
	cin>>a>>b;
	if(a*b==15) puts("*");
	else if(a+b==15) puts("+");
	else puts("x");
	return 0;
}

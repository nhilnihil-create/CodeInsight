#include<iostream>
#include<cstdio>
using namespace std;
int a,b,c;long long K;
int main(){
	scanf("%d%d%d%lld",&a,&b,&c,&K);
	if(K&1)printf("%d\n",b-a);else printf("%d\n",a-b);return 0;
}
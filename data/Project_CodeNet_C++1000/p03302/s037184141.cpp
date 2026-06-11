#include <iostream>
#include <cstdio>
#include <map>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
void read(int &x){
	char c=getchar();
	int k=1;
	while(c<'0'||c>'9') {if(c=='-') k=-1;c=getchar();}
	for(x=0;c>='0'&&c<='9';c=getchar())
	x=x*10+c-'0';
	x*=k;
}
int a,b;
int main(){
	cin>>a>>b;
	if(a*b==15) printf("*");
	else if(a+b==15) printf("+");
	else printf("x"); 
	return 0;
}

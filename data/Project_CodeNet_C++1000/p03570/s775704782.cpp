#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=2e5+10;
int f[1<<26],d[N];
char s[N];
int main(){
	memset(f,0x3f,sizeof f);
	scanf("%s",s);
	int ns=0,t;f[ns]=0;
	for (int i=0;s[i];++i){
		ns^=1<<(s[i]-'a');
		t=f[ns]+1;
		for (int j=0;j<26;++j) t=min(t,f[ns^(1<<j)]+1);
		f[ns]=min(f[ns],t);
	}
	printf("%d",t);
	return 0;
}
#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <bitset>
using namespace std;

/*
typedef long long ll;
bool Finish_read;
template<class T>
inline void read(T &x) {
	Finish_read=0;x=0;int f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	x*=f;Finish_read=1;
}
template<class T>
inline void print(T x) {
	if(x/10!=0)
		print(x/10);
	putchar(x%10+'0');
}
template<class T>
inline void writeln(T x) {
	if(x<0)
		putchar('-');
	x=abs(x);
	print(x);
	putchar('\n');
}
template<class T>
inline void write(T x) {
	if(x<0)
		putchar('-');
	x=abs(x);
	print(x);
}
/*================Header Template==============*/
const int mx=(1<<26);
int pos[mx],f[200010];
char s[200010];
bitset<26> x[200010];
int main() {
	scanf("%s",s+1);
	int n=strlen(s+1);
	f[0]=0;
	memset(pos,-1,sizeof pos);
	pos[0]=0;
	for(int i=1;i<=n;i++) {
		x[i]^=x[i-1];
		x[i][s[i]-'a']=1-x[i][s[i]-'a'];
		f[i]=2e9;
		int t=x[i].to_ulong(),ind=i;
		for(int j=0;j<26;j++) {
			int tmp=(1<<j)^t;
			if(pos[tmp]!=-1&&f[ind]>f[pos[tmp]])
				ind=pos[tmp];
		}
		if(pos[t]!=-1&&f[ind]>f[pos[t]])
			ind=pos[t];
		f[i]=f[ind]+1;
		if(pos[t]==-1||f[i]<f[pos[t]])
			pos[t]=i;
	}
	printf("%d\n",f[n]);
	return 0;
}
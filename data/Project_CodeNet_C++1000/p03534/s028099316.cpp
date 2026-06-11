#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline int max(int a, int b) {return a>b ? a : b;}
inline int min(int a, int b) {return a<b ? a : b;}
const int N = 102000;
char s[N];
int n,buc[4];

int main() {
	scanf("%s",s+1); n=strlen(s+1);
	rep(i,1,n) buc[s[i]-'a'+1]++;
	int x=1000000; rep(i,1,3) x=min(x,buc[i]);
	rep(i,1,3) buc[i]-=x;
	printf("%s", (buc[1]<=1&&buc[2]<=1&&buc[3]<=1) ? "YES" : "NO");
	return 0;
}
#include <bits/stdc++.h>
#define mset(a,b) memset(a,b,sizeof a)
#define mcpy(a,b) memcpy(a,b,sizeof b)
#define lb(x) ((x)&(-(x)))
#define xx first
#define yy second
#define pb push_back
#define mp make_pair
#define pii pair<int,int> 
#define dalao 1000000007
#define inf 0x3f3f3f3f
#define M (1<<26|1)
#define N 200010
using namespace std;
typedef long long ll;
int n,x,t,f[M];
char s[N];
int main(){
	scanf("%s",s),n=strlen(s);
	mset(f,0x3f),f[0]=0;
	for(int i=0;i<n;i++){
		s[i]-='a',x^=1<<s[i];
		t=f[x]+1;
		for(int j=0;j<26;j++)t=min(t,f[x^(1<<j)]+1);
		f[x]=min(f[x],t);
	}
	printf("%d",t);
	return 0;
}
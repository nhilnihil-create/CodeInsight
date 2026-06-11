#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)(x).size())
#define mset(a,v) memset(a,v,sizeof(a))
#define mcopy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

int dp[302][302][302];
char s[302];int n,k;

int f(int i, int j, int k){
	int& r=dp[i][j][k];
	if(r>=0)return r;
	if(i==0||j==n)r=0;
	else if(s[i-1]==s[j])r=1+f(i-1,j+1,k);
	else {
		r=max(f(i-1,j,k),f(i,j+1,k));
		if(k)r=max(r,1+f(i-1,j+1,k-1));
	}
	return r;
}

int main(){
	memset(dp,-1,sizeof(dp));
	scanf("%s%d",s,&k);n=strlen(s);
	int r=0;
	fore(i,0,n)r=max(r,2*f(i,i,k)),r=max(r,2*f(i,i+1,k)+1);
	printf("%d\n",r);
	return 0;
}
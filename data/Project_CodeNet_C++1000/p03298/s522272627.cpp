#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=100;
int gi(){
    char ch=getchar(); int x=0,q=0;
    while(ch<'0'||ch>'9') q=ch=='-'?1:q,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return q?-x:x;
}
int n,m,f[N][N],la,lb;
ll ans;
char s[N],a[N],b[N];
void dfs(int x){
    if (x>n){
	for (int i=0; i<=la; ++i)
	    for (int j=0; j<=lb; ++j)
		f[i][j]=0;
	f[0][0]=1;
	for (int i=0; i<=la; ++i)
	    for (int j=0; j<=lb; ++j){
		if (s[m-i-j]==a[i+1]) f[i+1][j]+=f[i][j];
		if (s[m-i-j]==b[j+1]) f[i][j+1]+=f[i][j];
	    }
	ans+=f[la][lb];
	return;
    }
    a[++la]=s[x],dfs(x+1),--la;
    b[++lb]=s[x],dfs(x+1),--lb;
    return;
}
int main(){
    scanf("%d%s+1",&n,s+1),m=2*n;
    dfs(1);
    cout<<ans;
    return 0;
}

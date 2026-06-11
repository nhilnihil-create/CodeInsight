#include<bits/stdc++.h>
using namespace std;

const int N = 2e5;
const int MOD = 1e9+7;

int dmod(int x){
	return x%MOD;
}

int n;
int c[N+5];
int li[N+5];
int nxt[N+5];

int memo[N+5];

int dp(int x){
	if(x > n) return 1;
	int &ret = memo[x];
	if(ret!=-1) return ret;
	ret = dp(x+1); // skip
	if(nxt[x] != -1 && nxt[x] != x+1) ret = dmod(ret + dp(nxt[x]));
	return ret;
}

int main(){
	memset(memo,-1,sizeof(memo));
	memset(c,-1,sizeof(c));
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&li[i]);
//		nxt[i] = c[li[i]];
//		c[li[i]] = i;
//		cout << ">> " << nxt[i] << endl;
	}
	for(int i=n;i>=1;i--){
		nxt[i] = c[li[i]];
		c[li[i]] = i;
	}
	int ans = dp(1);
	printf("%d\n",ans);
	return 0;
}
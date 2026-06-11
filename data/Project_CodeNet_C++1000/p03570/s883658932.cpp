#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MS(a) memset(a,0,sizeof(a))
#define MP make_pair
#define PB push_back
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3fLL;
inline ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
//////////////////////////////////////////////////////////////////////////
const int maxn = 2e5+10;

char s[maxn];
int a[maxn],dp[maxn],best[(1<<26)];

int main(){
	scanf("%s",s);
	int len = strlen(s);
	for(int i=0; i<len; i++)
		a[i+1] = (a[i]^(1<<(s[i]-'a')));
	memset(dp,INF,sizeof dp);
	memset(best,INF,sizeof best);
	dp[0] = 0;
	best[0] = 0;
	for(int i=1; i<=len; i++){
		int new_a = a[i];
		for(int bit=-1; bit<26; bit++){
			if(bit>=0) new_a = a[i]^(1<<bit);
			dp[i] = min(dp[i],best[new_a]+1);
		}
		best[a[i]] = min(best[a[i]],dp[i]);
	}
	cout << dp[len] << endl;

    return 0;
}
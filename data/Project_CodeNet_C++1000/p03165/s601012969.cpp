#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define me memset
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
using namespace std;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;

inline int read()
{
	int X=0; bool flag=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') flag=0; ch=getchar();}
	while(ch>='0'&&ch<='9') {X=(X<<1)+(X<<3)+ch-'0'; ch=getchar();}
	if(flag) return X;
	return ~(X-1);
}

char s[N],t[N];
int dp[10000][10000];

int main() {
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	scanf("%s %s",s+1,t+1);
	int len1=strlen(s+1);
	int len2=strlen(t+1);

	for(int i=1;i<=len1;++i){
		for(int j=1;j<=len2;++j){
			if(s[i]==t[j]) dp[i][j]=dp[i-1][j-1]+1;
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}

	int i=len1,j=len2;
	char ans[N];
	int cnt=0;
	while(dp[i][j]){
		if(s[i]==t[j]){
			ans[++cnt]=s[i];
			i--;
			j--;
		}
		else if(dp[i][j]==dp[i-1][j]) i--;
		else if(dp[i][j]==dp[i][j-1]) j--;
	}

	for(int i=cnt;i>=1;--i) printf("%c",ans[i]);

    return 0;
}
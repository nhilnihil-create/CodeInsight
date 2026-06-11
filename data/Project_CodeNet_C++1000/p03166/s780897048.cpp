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

int n,m;
int a,b;
vector<int> v[N];
int in[N];
int dp[N];

int main() {
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	n=read();
	m=read();

	for(int i=1;i<=m;++i){
		a=read();
		b=read();
		v[a].pb(b);
		in[b]++;
	}

	queue<int> q;
	for(int i=1;i<=n;++i){
		if(!in[i]) q.push(i);
	}

	while(!q.empty()){
		int now=q.front();
		q.pop();

		for(auto w:v[now]){
			in[w]--;
			if(!in[w]){
				q.push(w);
				dp[w]=dp[now]+1;
			}
		}
	}

	int ans=0;

	for(int i=1;i<=n;++i){
		ans=max(ans,dp[i]);
	}

	printf("%d\n",ans);

    return 0;
}
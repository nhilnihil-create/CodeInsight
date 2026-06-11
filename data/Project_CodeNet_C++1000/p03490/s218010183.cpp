#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<iostream>
#include<queue>
#include<string>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<long long,long long> pll;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i,j,k)  for(register int i=(int)(j);i<=(int)(k);i++)
#define rrep(i,j,k) for(register int i=(int)(j);i>=(int)(k);i--)

ll read(){
	ll x=0,f=1;char c=getchar();
	while(c<'0' || c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0' && c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}

string s;
vector<int> a,b;
bool dp[5050][16080];

int main(){
	cin>>s;int x=read(),y=read();s=s+'T';
	int cnt=0;int flag=1;
	for(int i=0;i<s.size();i++){
		if(s[i]=='T'){
			if(flag) a.pb(cnt); else b.pb(cnt);
			cnt=0;flag^=1;
		}
		else cnt++;
	}
	dp[1][a[0]+8010]=1;
	for(int i=1;i<a.size();i++){
		int nw=a[i];
		for(int j=0;j<16030;j++){
			if(dp[i][j]){
				if(j>=nw) dp[i+1][j-nw]=1;
				if(j+nw<=16020) dp[i+1][j+nw]=1;
			}
		}
	}
	bool ok=1;
	if(dp[a.size()][x+8010]) ok=1;else ok=0;
	memset(dp,0,sizeof(dp));
	dp[0][8010]=1;
	for(int i=0;i<b.size();i++){
		int nw=b[i];
		for(int j=0;j<16030;j++){
			if(dp[i][j]){
				if(j>=nw) dp[i+1][j-nw]=1;
				if(j+nw<=16020) dp[i+1][j+nw]=1;
			}
		}
	}
	if(dp[b.size()][y+8010]); else ok=0;
	if(ok)puts("Yes");
	else puts("No");
	return 0;
}

/*
AuThOr GaRyMr
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int maxi[1<<26],mask,dp[200000+1];
int main(){
	fastio;
	string s;
	cin>>s;
	memset(maxi,63,sizeof(maxi));
	maxi[0]=0;
	int len=s.length();
	rep(i,len){
		mask^=1<<(s[i]-'a');
		dp[i]=maxi[mask]+1;
		rep(j,26){
			dp[i]=min(dp[i],maxi[mask^(1<<j)]+1);
		}
		maxi[mask]=min(maxi[mask],dp[i]);
	}
	cout<<dp[len-1]<<endl;
	return 0;
}

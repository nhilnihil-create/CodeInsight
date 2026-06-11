// i hope i get better                                                           
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int sz=2e5+9;
int dp[sz][3];
int n;
string s;

int solve(int idx,int prv){
	int &ret=dp[idx][prv];
	if(~ret) return ret;
	if(idx==n) return ret=0;
	ret=0;
	if(prv==1&&s[idx]=='.') return ret=solve(idx+1,prv)+1;
	ret=solve(idx+1,s[idx]=='#');
	if((prv==1&&s[idx]=='#')==0) ret=min(ret,1+solve(idx+1,s[idx]!='#'));
	return ret;
}

int main(){
	cin>>n>>s;
	memset(dp,-1,sizeof(dp));
	cout<<solve(0,2);
	return 0;
}
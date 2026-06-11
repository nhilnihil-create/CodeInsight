#include <bits/stdc++.h>
 
using namespace std;
 
#define mp make_pair
#define endl '\n'
using ll=long long;
 
const int INF=1e9+5;
const ll lim=(ll)3e16;
const int N=3e3+5;
const int mod=1e9+7;
const ll oo=1e18+5;
 

void add_self(int& a,int b){
	a+=b;
	if(a>=mod) a-=mod;
}

int n;
string s;
int dp[N][N]; 
int pref[N][N];  

// TLE
// use prefix 

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
	cin>>n>>s;
	dp[1][1]=1;
	for(int pos=0;pos<n-1;++pos){
		int cur_sign=pos+2;
		for(int i=1;i<=cur_sign-1;++i){
			pref[cur_sign-1][i]=(pref[cur_sign-1][i-1]+dp[cur_sign-1][i])%mod;
		}
		for(int i=1;i<=cur_sign;++i){
			int l,r;
			if(s[pos]=='<'){
				l=1;
				r=i-1;
			}
			else{
				l=i;
				r=cur_sign-1;
			}
			if(l<=r){
				add_self(dp[cur_sign][i],(pref[cur_sign-1][r]-pref[cur_sign-1][l-1]+mod)%mod);
			}
		}
	}
	int ans=0 ;
	for(int i=1;i<=n;++i) add_self(ans,dp[n][i]);
	cout<<ans;
	return 0;
}


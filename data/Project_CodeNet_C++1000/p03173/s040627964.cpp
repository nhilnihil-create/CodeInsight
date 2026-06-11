#include<bits/stdc++.h>
#include <unistd.h>
using namespace std;
#define nl cout<<"\n"
#define pb push_back
#define se second
#define fi first
#define int long long 
#define pi pair<int,int>
#define vpi vector<pi>
#define vvpi vector<vpi>
#define fio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define For(i,n) for(int i=0;i<n;i++)
#define Forn(i,a,n) for(int i=a;i<n;i++)
#define pie =3.14159265358979323846264338327950;
const int mod= 1e9+7;

const int mx= 405;
int dp[mx][mx];

int sum(int l,int r, vector<int> &ar){
	int ans=0;
	for(int i=l;i<=r;i++){
		ans+=ar[i];
	}
	return ans;
}

void solve(){
	fio;
	int n;
	cin>>n;
	vector<int> ar(n);
	For(i,n) cin>>ar[i];
	for(int l=n-1;l>=0;l--){
		for(int r=l;r<n;r++){
			if(r==l){
				dp[l][r]=0;
			}
			else{
				dp[l][r]=1e18;
				int s= sum(l,r,ar);
				for(int i=l;i<=r-1;i++){
					dp[l][r]=min(dp[l][r],dp[l][i]+dp[i+1][r]+s);
				}
			}
		}
	}
	cout<<dp[0][n-1]<<endl;
}

int32_t main(){
	fio;
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int t=1;
	//cin>>t;
	for(int i=1;i<=t;i++){ 
		//cout<<"Case #"<<i<<":\n";
		solve();
	}
	return 0;
}

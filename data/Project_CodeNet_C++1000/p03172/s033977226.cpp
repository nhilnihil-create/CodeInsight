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


void solve(){
	fio;
	int n,k;
	cin>>n>>k;
	int ar[n];
	For(i,n) cin>>ar[i];
	vector<int> dp(k+1);
	dp[0]=1;
	for(int i=0;i<n;i++){
		vector<int> temp(k+1);
		for(int j=k;j>=0;j--){
			int l=j+1;
			int r= j+min(ar[i],k-j);
			if(l<=r){
				temp[l]+=dp[j];
				temp[l]%=mod;
				if(r+1<=k){
					temp[r+1]-=dp[j];
					if(temp[r+1]<0){
						temp[r+1]+=mod;
					}
				}
			}
		}
		for(int i=1;i<k+1;i++){
			temp[i]+=temp[i-1];
			temp[i]%=mod;
		}
		for(int i=0;i<k+1;i++){
			dp[i]+=temp[i];
			dp[i]%=mod;
		}
	}
	cout<<dp[k]%mod<<endl;
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

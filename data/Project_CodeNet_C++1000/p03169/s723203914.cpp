#include <bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<b;i++)
#define f(i,n) for(int i=0;i<n;i++)
typedef unsigned long long ull;
typedef long long ll;
#define vint vector<int>
#define pb(a) push_back(a);
#define bug(x) cout<<#x<<" = "<<x<<"\n";
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)

template <typename t>
void printarr(t *a,int n){
	f(i,n){
		cout<<a[i]<<" ";
	}
	cout<<"\n";
}

template <typename t>
void printvec(vector<t> a){
	for(int i=0;i<a.size();i++){
		cout<<a[i]<<" ";
	}
	cout<<"\n";
	return;
}

double dp[302][302][302];

double func(int i,int j, int k, int n){
	// cout<<"call done to "<<i<<" "<<j<<" "<<k<<"\n";
	if(i+j+k==0){dp[0][0][0]=0;		return  0;}
	else if(dp[i][j][k]!=-1){
		return dp[i][j][k];
	}
	double ss = (double)i+(double)j+(double)k;
	// cout<<ss<<"\n";
	dp[i][j][k] = (double)n/ss;
	// cout<<dp[i][j][k]<<"\n";
	if(i!=0){	dp[i][j][k] += (i*func(i-1,j,k,n))/ss;}
	if(k!=0){	dp[i][j][k] += (k*func(i,j+1,k-1,n))/ss;}
	if(j!=0){	dp[i][j][k] += (j*func(i+1,j-1,k,n))/ss;}
	// cout<<fixed<<setprecision(10)<<dp[i][j][k]<<"\n";
	return dp[i][j][k];
}

int main(){
	fastio;
	int n; cin>>n;
	int temp;
	int count[4]={0,0,0,0};
	f(i,n){
		cin>>temp;
		count[temp]++;
	}
	f(i,302){f(j,302){f(k,302){
		dp[i][j][k]=-1.00;
		// cout<<dp[i][j][k]<<" ";
	}// cout<<endl;
	}}
	double ans = func(count[1],count[2],count[3],n);
	cout<<fixed<<setprecision(13)<<ans<<"\n";
	return 0;
}
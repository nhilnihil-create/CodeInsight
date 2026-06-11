#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pair<int,int>>
#define vpll vector<pair<ll,ll>>
#define fr(i,k,n) for (int i = k; i < n; ++i)
#define fri(i,k,n) for (int i = k; i >= n; --i)
#define INF (int)1e9
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define all(arr) arr.begin(),arr.end()

void boost(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

ld dp[302][302][302];
int n;
ld rec(int i,int j,int k){
	if(i<0 || j<0 || k<0)
		return 0;
	if(i==0 && j==0 && k==0)
		return 0;
	if(dp[i][j][k]>0)
		return dp[i][j][k];
	ld x=i+j+k;
	dp[i][j][k]=i*rec(i-1,j,k) + j*rec(i+1,j-1,k) + k*rec(i,j+1,k-1) +(ld)(n);
	dp[i][j][k]/=x;
	return dp[i][j][k];
}

void solve(){
	cin>>n;
	int a;
	int one=0,two=0,three=0;
	fr(i,0,n){
		cin>>a;
		if(a==1)
			one++;
		else if(a==2)
			two++;
		else if(a==3)
			three++;
	}
	cout<<fixed<<setprecision(12)<<rec(one,two,three)<<endl;
	return;
}

int main()
{
	boost();
	
	int tc=1;
	//cin>>tc;
	while(tc--)
		solve();
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
const int mod = 1e9+7;
const int mx = INT_MAX;
const long double pi = 4*atan((long double)1);
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;
#define file "orz"
int arr[5][105];
int dp[5][105];
int main()
{
    //freopen(file".inp","r",stdin);
    //freopen(file".out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=2;i++)
	    for(int j=1;j<=n;j++)
	    	cin>>arr[i][j];
    for(int i=1;i<=2;i++)
    	for(int j=1;j<=n;j++)
    		dp[i][j] = max(dp[i-1][j],dp[i][j-1])+arr[i][j];
    cout<<dp[2][n];
//   for(int i=1;i<=2;i++)
//   {
//   	for(int j=1;j<=n;j++)
//   		cout<<dp[i][j]<<" ";
//	cout<<endl;
//   }
}

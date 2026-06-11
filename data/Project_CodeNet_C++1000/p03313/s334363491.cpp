#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(),x.end()
#pragma 03
const int mod = 1e9+7;
const int mx = INT_MAX/10;
const long double pi = 4*atan((long double)1);
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;
#define file "orz"
const int mxN=1e6+5;
int n,arr[mxN],dp[mxN];
signed main()
{
	//freopen(file".inp","r",stdin);
    //freopen(file".out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=0;i<(1<<n);i++)
    	cin>>arr[i];
    for(int mask=1;mask<(1<<n);mask++)
    {	
    	int temp=0, temp2=0;
    	for(int i=mask;;i=(i-1)&mask)
    	{
    		if(temp<arr[i])
    		{
    			temp2=temp;
    			temp=arr[i];
			}
			else
				temp2=max(temp2,arr[i]);
			if(!i)
				break;
		}
		dp[mask]=max(dp[mask-1],temp+temp2);
		cout<<dp[mask]<<"\n";
	}
}

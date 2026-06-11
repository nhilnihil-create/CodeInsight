#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define ld long double
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rloop(i,a,b) for(int i=a;i>=b;i--)
const int inf=1e9+7;
 
static bool compare(vector<int> v1,vector<int> v2)
{
    return (v1[1]<v2[1] || (v1[1]==v2[1] && v1[0]<v2[0]));
}
bool isprime(ll x)
{
	for(ll i=2;i*i<=x;i++)
	{
		if(x%i==0)
		return false;
	}
	return true;
}


int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2==1) nums[i]=1;
            else nums[i]=0;
        }
        loop(i,0,n)
        cout<<nums[i]<<" ";
        cout<<endl;
        vector<int> prsum(n);
            prsum[0]=nums[0];
        map<int,int>  mp;
        mp[prsum[0]]++;
        for(int i=1;i<n;i++)
        {
            prsum[i]=prsum[i-1]+nums[i];
            mp[prsum[i]]++;
        }
        loop(i,0,n)
        cout<<prsum[i]<<" ";
        cout<<endl;
        int ans=0;
        for(int i=prsum[n-1];i>=k;i--)
        {
            if(i!=k)
            {
                ans+=mp[i]*mp[i-k];
            }
            else
            {
                ans+=mp[i]*(mp[0]+1);
            }
            cout<<ans<<endl;
        }
        return ans;
        
    }

int main()
{
	ll n,k;
	cin>>n>>k;
	ll a[n+1];
	loop(i,1,n+1)
	{
		cin>>a[i];
	}
	vector< vector<ll> > dp(n+1, vector<ll> (k+1,1));
	loop(i,1,k+1)
	{
		if(a[1]>=i)
		dp[1][i]=1;
		else 
		dp[1][i]=0;
	}
	loop(i,2,n+1)
	{
		ll pre[k+1];
		pre[0]=dp[i-1][0];
		loop(j,1,k+1)
		{
			pre[j]=(dp[i-1][j]+pre[j-1])%inf;
			
			if(j<=a[i])
			dp[i][j]=pre[j];
			else
			dp[i][j]=(pre[j]-pre[j-a[i]-1]+inf)%inf;
//			cout<<dp[i][j]<<" ";
		}
//		cout<<endl;
	}
	cout<<dp[n][k]%inf;
	return 0;
}


//5 3
//1 1 2 1 1


//10 2
//2 2 2 1 2 2 1 2 2 2

#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define endl "\n"
#define pii pair<int,int>
#define pll pair<ll,ll>
typedef long long ll;
#define loop() for(int i=0; i<(); i++)
const int MOD=1e9+7;
int modpow(int x, int n, int m)
{
    if(n==0) return 1;
    ll ans=1;
    while(n>0)
    {
        if(n%2==1) ans=(ans*x)%m;
        x=(x*x)%m;
        n/=2;
    }
    return ans;
}

void solve()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    map<int,int>m;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        m[a[i]]++;
    } 
    sort(a,a+n);
    vector<int>dp(k+1,2);
    dp[0]=0;
    for(int i=1; i<=k; i++)
    {
        if(m.count(i))
        {
             dp[i]=0;
             continue;
        }
        for(int j=0; j<n && a[j]<=i; j++)
        {
            if(dp[i-a[j]]==1) 
            {
                dp[i]=0;
                break;
            }
        }
         if(dp[i]==2) dp[i]=1;
        
    }
    if(dp[k]==0) cout<<"First"<<endl;
    else cout<<"Second"<<endl;
    
}   

int main(){
	fast
	int t=1;
	//cin>>t;
	while(t--) solve();

}

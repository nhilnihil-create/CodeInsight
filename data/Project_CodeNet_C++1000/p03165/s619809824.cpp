#include<bits/stdc++.h>
#define fr(i,a,n) for(ll i=a;i<n;i++)
#define YES cout<<"YES"<<endl
#define all(v) v.begin(),v.end()
#define NO cout<<"NO"<<endl
#define pb(x) emplace_back(x)
#define fastio std::ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define vi vector<ll>
#define mi map<ll,ll>
#define pi pair<ll,ll>
#define what(x) cout<<#x<<" ="<<x<<endl;
using namespace std;
using ll =long long;

ll dp[3005][30005];

int main()
{
    string a,b;
    cin>>a>>b;
    ll n=a.size();
    ll m=b.size();

    fr(i,0,n)
    {
        fr(j,0,m)
        {

            if(a[i]==b[j])dp[i+1][j+1]=1+dp[i][j];
            else dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
        }
    }

    ll i=n,j=m;
    string ans="";
    while(i!=0 && j!=0 )
    {
        if(a[i-1]==b[j-1])
        {
            ans+=a[i-1];
            i--;j--;
        }
        else
        {
            if(dp[i-1][j]>=dp[i][j-1])i--;
            else j--;
        }
    }

    for(ll i=ans.size()-1;i>=0;i--)
        cout<<ans[i];
    cout<<endl;








}



























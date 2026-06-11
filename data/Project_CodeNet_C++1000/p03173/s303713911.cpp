#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define uu unsigned
#define io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define MOD 1000000007
#define pi pair<int,int>
#define pl pair<ll,ll>
#define mkp make_pair
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define ss second
#define ff first
#define mit map<ll,ll>::iterator
#define it(x,type) x<type>::iterator
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define printf __mingw_printf
#define printcas cout<<"Case "<<cas<<": "
#define _ continue;
#define endl '\n'
#define __ cout<<endl;continue;
#define vec2d(nam,type,row,col,fix) vector<vector<type>> nam(row,vector<type>(col,fix))
#define vec4d(nam,type,a,b,c,d,fix) vector<vector<vector<vector<type>>>> nam(a,vector<vector<vector<type>>>(b,vector<vector<type>>(c,vector<type>(d,fix))))

int main()
{
     io;
    //string hudai(1000000,'a');
    int T=1;
    //cin>>T;
     for(int cas=1;cas<=T;cas++)
    {
        ll n,i,j,k,l    ;
        cin>>n;
        vl sum(n+3);vec2d(dp,ll,n+2,n+2,1e18);
        sum[0]=0,sum[n+1]=1e18;
        for(i=1;i<=n;i++)
        {
            cin>>k;
            sum[i]=sum[i-1]+k;
        }

        for(i=1;i<=n;i++)
        {
            dp[i][i]=0;
            dp[i][i+1]=sum[i+1]-sum[i-1];
        }
        for(k=2;k<=n-1;k++)
        {
            for(i=1;i+k<=n;i++)
            {
                for(l=i;l<i+k;l++)
                {
                    dp[i][i+k]=min(dp[i][i+k],dp[i][l]+dp[l+1][i+k]);
                }
                dp[i][i+k]=dp[i][i+k]+(sum[i+k]-sum[i-1]);
            }
        }
        cout<<dp[1][n];

    }
    return 0;
}

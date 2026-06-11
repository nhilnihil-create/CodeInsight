#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define modd 998244353
#define PI 3.1415926
#define ll long long
#define ld long double
#define pb push_back
#define popb pop_back
#define beg begin()
#define en end()
#define sz(v) (int)((v).size())
#define all(v) (v).begin(),(v).end()
#define ub upper_bound
#define lb lower_bound
#define ff first
#define ss second
#define endl "\n"
#define forn(i,a,n) for(int i=a;i<int(n);++i)
#define forb(i,a,n) for(int i=int(n)-1;i>=a;--i)
#define cout(ans) cout<< ans << "\n"
#define couts(ans) cout<< ans <<" "
#define coutss(a,b) cout<< a <<" "<< b << "\n"
#define coutsm(a,b,c) cout<< a <<" "<< b <<" "<< c << "\n"
#define maxx *max_element
#define minn *min_element


void speed()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
}



ld dp[3005][3005];
ld p[3005];

void solve()
{      
    int n;cin>>n;
    // ld p[n+1];
    forn(i,1,n+1)
    {
        cin>>p[i];
    }
    // ld dp[n+1][n+1];
    // memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    // dp[1][0]=1-p[0];
    // dp[1][1]=p[0];
    // coutss(dp[0][1],"DJJ");
    forn(i,1,n+1)
    {
        forn(j,0,i+1)
        {
            // coutsm(dp[0][1],i,j); 

            // if(j)
            {
                dp[i][j]=dp[i-1][j]*(1-p[i])+dp[i-1][j-1]*p[i];
                // if(i==2 && j==1)
                // coutsm(dp[i][j],dp[i-1][j]*(1-p[i-1]),dp[i-1][j-1]*p[i-1]);
            }
            // else
            // {
            //     dp[i][j]=dp[i-1][j]*(1-p[j-1]);
            // }

            // coutsm(dp[1][1],i,j); 

        }
    }
    // forn(i,1,n+1)
    // {
    //     forn(j,0,i+1)
    //     {
    //        coutsm(dp[i][j],i,j);
    //     }
    //     // cout<<endl;
    // }


    ld ans=0;
    forn(i,1,n+1)
    {
        if(i>(n-i))
        {
            ans+=dp[n][i];
        }
    }
    cout<<fixed<<setprecision(9)<<ans<<endl;

}


int main()
{   
    speed();
    int tc=1;
    // cin>>tc;
    while(tc--)
    {
        solve();
    }
}
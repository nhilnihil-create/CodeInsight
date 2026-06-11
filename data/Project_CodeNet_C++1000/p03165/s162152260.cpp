#include<bits/stdc++.h>

#define  ll         long long
#define  llu        unsigned long long
#define  mod        1000000007
#define  pi         ((2.0)*acos(0.0))
#define  pb         push_back
#define  pf         push_front
#define  eb         emplace_back
#define  mp         make_pair
#define  all(x)     (x).begin(),(x).end()
#define  X          first
#define  Y          second

/*loop*/
#define  fr(i,m,n)   for(ll i=m;i<n;++i)

/*output shortcuts*/
#define  nl         "\n"
#define  Yes        cout<<"Yes\n"
#define  yes        cout<<"yes\n"
#define  YES        cout<<"YES\n"
#define  No         cout<<"No\n"
#define  no         cout<<"no\n"
#define  NO         cout<<"NO\n"

using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s,t;
    cin>>s>>t;

    ll x=s.size();
    ll y=t.size();

    ll dp[x+1][y+1];
    char dir[x+1][y+1];

    fr(i,0,x+1)
    {
        fr(j,0,y+1)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
                continue;
            }

            if(s[i-1]==t[j-1])
            {
                dir[i][j]='S';
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else
            {
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);

                if(dp[i][j]==dp[i][j-1])
                    dir[i][j]='L';
                else
                    dir[i][j]='U';
            }
        }
    }
        //cout<<dp[x][y]<<nl;
        /*printing the sub-string*/
        ll a=dp[x][y];
        //cout<<a<<nl;
        string sub="";
        while(a>0)
        {
            if(dir[x][y]=='S')
            {
                sub.pb(s[x-1]);
                x--; y--; a--;
                continue;
            }
            if(dir[x][y]=='L')
            {
                y--; continue;
            }
            if(dir[x][y]=='U')
            {
                x--; continue;
            }
        }

        reverse(all(sub));

        cout<<sub<<nl;

return 0;
}

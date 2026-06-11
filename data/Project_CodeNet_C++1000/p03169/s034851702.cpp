#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

double dp[301][301][301];
double ans=0;
ll n;

void solve(ll a, ll b, ll c)
{

 
    if (dp[a][b][c]!=-1)
    {
        return;
    }
    else
    {
        dp[a][b][c]=0;
    }
    if (a==0&&b==0&&c==0)
    {
        return;
    }
    dp[a][b][c]+=(double)n/(double)(a+b+c);

    if(a!=0&&b!=0&&c!=0)
    {
        solve(a-1, b, c);
        solve(a+1, b-1, c);
        solve(a, b+1, c-1);
        dp[a][b][c] += (a*(dp[a-1][b][c]) + b*dp[a+1][b-1][c] + c*dp[a][b+1][c-1])/(a+b+c) ;
    }
    else if(a!=0&&b!=0)
    {
        solve(a-1, b, c);
        solve(a+1, b-1, c);
        dp[a][b][c] += (a*(dp[a-1][b][c]) + b*dp[a+1][b-1][c] )/(a+b+c) ;
    }
    else if(a!=0&&c!=0)
    {
        solve(a-1, b, c);
        solve(a, b+1, c-1);
        dp[a][b][c] += (a*(dp[a-1][b][c])  + c*dp[a][b+1][c-1])/(a+b+c) ;
    }
    else if(b!=0&&c!=0)
    {
        solve(a+1, b-1, c);
        solve(a, b+1, c-1);
        dp[a][b][c] += (b*dp[a+1][b-1][c] + c*dp[a][b+1][c-1])/(a+b+c) ;
    }
    else if(a!=0)
    {
        solve(a-1, b, c);
        dp[a][b][c] += (a*(dp[a-1][b][c]))/(a+b+c) ;
    }

    else if(b!=0)
    {
        solve(a+1, b-1, c);
        dp[a][b][c] += (b*(dp[a+1][b-1][c]))/(a+b+c) ;
    }
    else if(c!=0)
    {
        solve(a, b+1, c-1);
        dp[a][b][c] += (c*(dp[a][b+1][c-1]))/(a+b+c) ;
    }
   
    


}

int main()
{
    cin >> n;
    ll a[n];
    ll cnt1=0, cnt2=0, cnt3=0;
    for (int i = 0; i < 301; ++i)
    {
        for (int j = 0; j < 301; ++j)
        {
            for (int k = 0; k < 301; ++k)
            {
                dp[i][j][k]=-1; 
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if (a[i]==1)
        {
            cnt1++;
        }
        if (a[i]==2)
        {
            cnt2++;
        }
        if (a[i]==3)
        {
            cnt3++;
        }
    }
    solve(cnt1, cnt2, cnt3);
    cout << fixed << setprecision(12)<< dp[cnt1][cnt2][cnt3];
    return 0;
}
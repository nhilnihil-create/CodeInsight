//AUTHOR: RAVAN_2070
//PUNE INSTITUTE OF COMPUTER TECHNOLOGY
//Atcoder Educational DP
//J-Sushi
/*
    I ♥ CLARICE STARLING

    EXPLAINATION BELOW->
    Dp + Probability

    First : what really matters is the number of dishes with 0, 1, 2 and 3 sushis and not the order of the dishes.
    So answer for 2,1,0,2,1 is same as answer for 0,1,1,2,2.
    Number of dishes with 0 sushis is easily determined by N - one - two - three, where one is the number of dishes with 1 sushi and N is the total number of dishes in the input.
    Let F(x, y, z) be the expected moves needed for x dishes with 1 sushi, y with 2 and z with 3.
    Now in the next move we can pick a dish with 1 sushi with a probability of x/N or p1. we can pick a dish with 2 sushi with a probability of y/N or p2. we can pick a dish with 3 sushi with a probability of z/N or p3. 
    we can pick a dish with 0 sushi with a probability of (N - (x + y + z))/N or p0.
    Now try to understand this :
    F(x,y,z) = 1 + p0F(x,y,z) + p1F(x-1,y,z) + p2F(x+1,y-1,z) + p3F(x,y+1,z-1)
   
*/
//
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define all(x) x.begin(),x.end()
#define fo(i,a,b) for(i=a;i<b;i++)
#define foe(i,a,b) for(i=a;i<=b;i++)
const ll INF=(ll)1e18+5;
void solve()
{
    ll n,i,j,k,t;cin>>n;
    ll one,two,three;one=two=three=0;
    fo(i,0,n)
    {
        cin>>t;
        if(t==1)one++;
        else if(t==2)two++;
        else three++;
    }
    double dp[n+1][n+1][n+1];//n*n*n since max possible 1's or 2's or 3's can be equal to n
    dp[0][0][0]=0;
    
    foe(k,0,n)
    {
        foe(j,0,n)
        {
            foe(i,0,n)
            {
                ll total=0;
                if(i==0&&j==0&&k==0)continue;
                if(i+j+k>n)continue;
                total=i+j+k;
                dp[i][j][k]=n;
                if(i>0)dp[i][j][k]+=i*dp[i-1][j][k];
                if(j>0)dp[i][j][k]+=j*dp[i+1][j-1][k];
                if(k>0)dp[i][j][k]+=k*dp[i][j+1][k-1];
                dp[i][j][k]/=total;
            }
        }
    }
    cout<<setprecision(16)<<dp[one][two][three]<<"\n";
    
}
int main()
{
   fastio
   solve();
  return 0;
}


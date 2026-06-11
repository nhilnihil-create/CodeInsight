#include<bits/stdc++.h>
#define ll long long
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define N 15000
using namespace std;

template <typename T>
void print(T x){cout<<x<<"\n";}
template <typename T1, typename T2>
void print2(T1 x,T2 y){cout<<x<<" "<<y<<"\n";}
template <typename T1, typename T2,typename T3>
void print3(T1 x, T2 y,T3 z){cout<<x<<" "<<y<<" "<<z<<"\n";}

int mincost(int n)
{
    int dp[n][3],a[n],b[n],c[n];
    for(int i=0;i<n;i++) cin>>a[i]>>b[i]>>c[i];

    dp[0][0]=a[0];
    dp[0][1]=b[0];
    dp[0][2]=c[0];

    for(int i=1;i<n;i++)
    {
        dp[i][0]=a[i]+max(dp[i-1][1],dp[i-1][2]);
        dp[i][1]=b[i]+max(dp[i-1][2],dp[i-1][0]);
        dp[i][2]=c[i]+max(dp[i-1][1],dp[i-1][0]);
    }

    return max(max(dp[n-1][0],dp[n-1][1]),dp[n-1][2]);
}

int main()
{
    io;
    ll test_case;
    //cin>>test_case;
    test_case=1;
    while(test_case--)
    {
        ll n,k;
        cin>>n;
        cout<<mincost(n)<<"\n";
    }   
}
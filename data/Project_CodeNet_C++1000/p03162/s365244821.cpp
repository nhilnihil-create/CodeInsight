//
#include"bits/stdc++.h"
 

// NOTE TO SELF // try to simplyfy the problem

#define rep(i,a,n) for (int i = a; i <= n; i++)

#define ll long long int

//const int mod=1000000007;
using namespace std;
 
/*int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, -1, 1};
*/


ll dp[100005][3];


int main()
{


    ll n;
    cin>>n;
    
    dp[0][0]=0;
    dp[0][1]=0;
    dp[0][2]=0;
    
    ll flag=1;
    
    ll k=n;
    
    while(k--)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        
        dp[flag][0]= a + max(dp[flag-1][1],dp[flag-1][2]);
        dp[flag][1]= b + max(dp[flag-1][2],dp[flag-1][0]);
        dp[flag][2]= c + max(dp[flag-1][1],dp[flag-1][0]);
        
        
        flag++;
        
    }
    
    cout<< max(dp[n][0],max(dp[n][1],dp[n][2]))<<endl;
    
    
}

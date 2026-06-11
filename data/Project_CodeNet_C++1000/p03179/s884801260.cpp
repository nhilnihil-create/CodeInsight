#include<iostream>
using namespace std ;
#define ll long long int
#define maxn  1000000007
#include<cstring>
int main()
{

    ll n ;
    cin>> n ;
    string s ;
    cin>>s ;
    ll dp[n+1][n+1] ;
    memset(dp, 0, sizeof((dp)) )  ;
    dp[0][1] =1 ;


    for( int i =0 ; i < n ;i++)
    {
        if(s[i]=='<')
        {

            ll sum[i+3]   ;
            memset(sum , 0 , sizeof( sum)) ;
            for(int j = 1 ;  j<= i+1 ;j++)
            {

                sum[j] = (sum[j-1]+ dp[i][j] ) %maxn   ;
            }

            for( ll j = 1 ;j <= i+2 ; j++ )
            {
                dp[i+1][j] = sum[j-1] ;


            }

        }else
        {




            ll sum[i+3]   ;
            memset(sum , 0 , sizeof( sum)) ;
            for(int j = 1+i ;  j>= 1 ;j--)
            {

                sum[j] = (sum[j+1]+ dp[i][j] )%maxn  ;
            }

            for( ll j = 1 ;j <= i+1 ; j++ )
            {
                dp[i+1][j] = sum[j] ;


            }

        }


    }














    ll ans =0 ;
    for( int i = 1 ;i <= n ;i++)
    {

        ans= (ans + dp[n-1][i] )%maxn ;
    }
    cout<<ans ;

}

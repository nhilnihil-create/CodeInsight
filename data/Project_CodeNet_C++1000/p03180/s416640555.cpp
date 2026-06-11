#include<iostream>
using namespace std ;
#define ll long long int
#include<vector>
#include<cstring>
ll pow(ll a ,ll b)
{

    if(b==0)
        return 1 ;
    ll c = pow( a, b/2) ;
    c= c*c ;
    if(b%2==1)
        c*= a ;
    return  c ;
}


vector<pair< ll ,ll > >  pr( ll  i )
{
    ll v = i ;
    vector<ll> aa ;
    ll ini = 1 ;
    aa.push_back( 0) ;
    while(i!=0)
    {


if( i%2==1)
{
        vector<ll> values ;
for( auto j :  aa)
{

    values.push_back( j+ ini) ;
}

aa.insert( aa.end() ,  values.begin() , values.end()) ;


}
i/=2 ;

        ini= ini*2 ;



    }
    vector<pair< ll ,ll > > ans ;
    for(auto j :  aa)
    {
        if(j==0 || j== v)
            continue ;
        ans.push_back(  make_pair( j ,  v^j)) ;
     
     
    }
return ans ;



}
int main()
{

    ll  n ;
        cin>> n ;
    ll arr[n][n] ;

    for(int i = 0 ;i < n ;i++)
    {

        for(ll j =0;j < n ;j++)
            cin>>arr[i][j] ;
    }


    ll cost [pow(2 , n) ] ;
    memset(cost ,  0 , sizeof(cost)) ;
    for( ll i =0 ;i< pow(2, n)  ;i++)
    {
        ll val  = i ;

        vector<ll> values ;
        ll ini = 0 ;
        ll sum = 0;
        while( val!=0 )
        {
            if(val%2==1)
            {

                for(auto is :  values )
                {
                    sum += arr[ini][is] ;


                }
                values.push_back( ini ) ;
            }

            val/=2 ;
            ini++ ;
        }
        

        cost[i] =sum ;
    }

    ll dp[pow(2, n)]  ;
    
    memset(dp ,  0 , sizeof(dp)) ;


 for( ll i =1 ;i<pow(2, n)  ;i++)
 {
     vector<pair<ll,ll>>  doi =  pr( i) ;
      ll maxn = cost[i] ;
      for(auto j :  doi)
      {
          maxn = max( maxn , dp[j.first ]+ dp[j.second]) ;

      }

      dp[i] = maxn ;


 }
 cout<<dp[pow(2,  n)-1] <<endl ; 



}

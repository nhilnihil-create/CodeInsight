#include<iostream>
#include<vector>
using  namespace std ;
#define ll long long int

class segment {
public :

ll n  ;
    vector<ll> arr ;
    void build ( ll n )
    {
        this->n = n+1 ;
    }


    void update( ll plac , ll  val )
    {

        do_up( 1 , 0 , n-1  , plac ,  val   ) ;


    }


    void do_up ( ll cur , ll ini , ll fin , ll loc , ll  val )
    {
        if(arr.size()< cur+1)
        {

            arr.resize(cur+1,  0 ) ;
        }

        if( ini> loc ||  loc>fin )
            return ;

        if(ini == fin && ini == loc )
        {

            arr[cur] = val ;
        }else
        {
            ll tm = ini + fin ;
            tm/=2 ;

            do_up( cur*2 ,  ini ,  tm ,  loc , val ) ;
            do_up( cur*2+1 ,   tm +1 , fin  ,  loc , val ) ;

            arr[cur] = max( arr[cur*2+1 ] ,  arr[cur*2])  ;


        }


    }

    ll val(ll  i )
    {

      return   do_fin( 1 ,  0 , n-1 , i ,i ) ;
    }


   ll  do_fin( ll cur , ll ini , ll  fin , ll lef ,ll rig )
    {

        if( lef  > rig )
            return  0 ;

        if(arr.size()< cur+1)
        {

            arr.resize(cur+1,  0 ) ;
        }

        if(ini == lef && fin==rig)
            return  arr[cur] ;

ll tm = ini +fin ;
tm/=2 ;
            ll l =  do_fin( cur*2 , ini , tm ,  lef , min( tm , rig )  ) ;
            ll r  = do_fin( cur*2+1 , tm+1 , fin ,  max( tm+1 , lef ) ,rig ) ;

            return max( l , r) ;

    }


    ll searc( ll i )
    {

        return do_fin ( 1, 0,   n-1 , 0 , i ) ;
     }

    };



int main()
{

    ll n ;cin>> n ;
    vector<ll> hig ( n) , val(n) ;
    for(ll i =0; i < n ;i++)
        cin>>hig[i] ;
    for(ll i =0; i < n ;i++)
        cin>>val[i] ;
    segment arr ;

    arr.build(1+n ) ;

    ll dp[n] = {0} ;
    for(ll i = 0 ;i <  n ;i++)
    {

        ll hi = hig[i] ;
        ll vla = 0 ;
        if(hi!=0)
        {
            vla = arr.searc( hi-1) ;


        }
        
        
        vla += val[i] ;
        ll ini = arr.val( hi ) ;
        if(ini < vla)
        {

            arr.update( hi,  vla ) ;
        }
        dp[i] = arr.val(hi) ;

    }

    ll maxn = 0 ;
    for(auto i : dp)
        maxn = max(maxn ,  i) ;
    cout<<maxn ;

}

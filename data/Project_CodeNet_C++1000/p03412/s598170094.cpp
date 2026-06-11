#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x) x.begin(),x.end()
#define pll  pair <long long,long long>
#define ss second
#define ff first
#define inf 9223372036854775807
#define maa 1000000007
#define mod 998244353
#define ld long double
#define fast  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define bug(x) cout << #x <<": " << x << '\n';
const ll N=10001 ;
int main()
{
   fast ;
   ll n ;
   cin>>n ;
   vector<ll>a(n),b(n) ;
   for(ll i=0;i<n;i++)
    cin>>a[i] ;

   for(ll i=0;i<n;i++)
    cin>>b[i] ;

   ll ans=0 ;
   for(ll i=0;i<29;i++)
   {
       vector<ll>na(n),nb(n) ;
       for(ll j=0;j<n;j++)
       {
           na[j]=a[j]%(1<<(i+1)) ;
           nb[j]=b[j]%(1<<(i+1)) ;
       }
       ll cnt=0 ;
       sort(all(na)) ;
       sort(all(nb)) ;

       for(ll j=0;j<n;j++)
       {
            auto it1=upper_bound(all(nb),(1<<(i+1))-1-na[j]) ;
            auto it=lower_bound(all(nb),(1<<i)-na[j]) ;


            ll x=(ll)(it1-it) ;
            x=max(x,(ll)0) ;
            cnt+=x ;


            it1=upper_bound(all(nb),(1<<(i+2))-2-na[j]) ;
            it=lower_bound(all(nb),(1<<(i+1))+(1<<i)-na[j]) ;

            x=(ll)(it1-it) ;
            x=max(x,(ll)0) ;
            cnt+=x ;


       }

       if(cnt%2)
       {
           ans+=(1<<i) ;
       }
   }
   cout<<ans ;


}


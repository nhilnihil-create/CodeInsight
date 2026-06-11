#include<bits/stdc++.h>
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
using namespace  std ;
typedef long l ;
typedef long long ll ;
typedef vector<int>vi ;
typedef vector<l>vl ;
typedef vector<ll>vll ;
typedef vector<vector<ll> >vvl ;
typedef pair<int,int> pii ;
typedef pair<ll,ll> pll ;
long long power(long long k , long long n , long long m=1e9+7)
{
    long long res = 1;
    while(n)
    {
        if(n%2!=0)
        {
            res = (res*k)%m ;
        }
        k = (k*k)%m ;
        n = n/2 ;
    }
    return(res) ;
}
long long fact(long long n , long long m = 1e9+7)
{
    long long a = 1 ;
    if(n==0 || n==1)
    {
        return(1) ;
    }
    while(n>0)
    {
        a = (a%m * n%m)%m ;
        n-- ;
    }
    return(a) ;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    std::cout.unsetf ( std::ios::floatfield );//this and next line for floating precision upto 6
    std::cout.precision(10);
    ll a,b,c,d,e,x,i,j,n,t,m,k,y;
    double p,q,r,w,u ;
    string str = "",str1 = "" ;
    ll a1,a2,b1,b2 ;
  	cin>>a>>b ;
  	if(b%a==0)
    {
      cout<<b+a ;
    }
  	else
    {
      cout<<b-a ;
    }
}
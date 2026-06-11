#include <bits/stdc++.h>
using namespace std;
 
typedef long long               ll;
typedef long double             ld;
 
 
#define racecar          ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define si(a)            scanf("%d", &a)
#define si2(a,b)         scanf("%d %d", &a,&b)
#define sll(a)           scanf("%I64d",&a)
#define sll2(a,b)        scanf("%I64d %I64d",&a,&b)
#define pb               push_back
#define pi(a)            printf("%d",int(a))
#define pll(a)           printf("%I64d",ll(a))
#define all(x)           (x).begin(),(x).end()
#define rall(x)          (x).rbegin(),(x).rend()
#define ps               printf(" ")
#define nln              printf("\n")
#define ff               first
#define ss               second
#define vi               vector<int>
#define vll              vector<ll>
#define vstr             vector<string>
#define vc               vector<char>
#define pii              pair<int,int>
#define PLL              pair<ll,ll>
#define PI               acos(-1)
#define sq(x)            x*x
#define forr(i,a,b)      for(ll i=ll(a);i<ll(b);i++)
#define forn(i,a,b)      for(ll i=ll(a);i>ll(b);i--)
#define max3(a,b,c)      max(a,max(b,c))
#define max4(a,b,c,d)    max(max3(a,b,c),d)
#define min3(a,b,c)      min(a,min(b,c))
#define mod              1000000007
#define inf              9223372036854775807
 
ll power(ll b,ll n)
{
    if(n==0) return 1;
    else if(n%2) return b*power(b,n/2)*power(b,n/2);
    else return power(b,n/2)*power(b,n/2);
} 
 
ld root(ll n,ll r)
{
    ld dif=0.0001;
    ld guess=n/2.0;
    while(abs(pow(guess,r)-n)>=dif)
    {
        ld temp=pow(guess,r)-n;
        ld tmp=r*pow(guess,r-1);
        guess-=temp/tmp;
    }
    return guess;
}
 
void fileio()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}
 
      
 
int solve()
{   
	ll n,a,b;
	sll(n);
	sll2(a,b);
	ll cnt=0;
	while(n--)
	{
		ll x,y;
		sll2(x,y);
		if(x>=a && y>=b) cnt++;
	}
	pll(cnt);
	
	return 0;
}
 
int main()
{   
 
//    racecar;
//    cout<<fixed<<setprecision(6);
//    fileio();
    solve();
}
 
 
 
///    Before submission=>
///    ***check for integer overflow,array bounds
///    ***check for n
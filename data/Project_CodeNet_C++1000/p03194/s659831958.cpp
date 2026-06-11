

#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL); 

#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define mp make_pair
#define pu push
#define pp pop_back
#define in insert
#define ld long double
#define endl '\n'
#define debug cout << "Hold right there sparky.....\n";
#define forn(low,high,i) for(i=low;i<high;i++)
#define forrev(high,low,i) for(i = high; i>= low;i--)
#define trace(x) cerr << #x << ": " << x << " " << endl;

typedef long long int ll;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
const ll mod =1e9+7;

ll power(ll x,ll y) 
{   
    x%=mod;
    if (y == 0) 
        return 1; 
    ll p = power(x, y/2) % mod; 
    p = (p * p) % mod; 
  
    return (y%2 == 0)? p : (x * p) % mod; 
}
int main()
{
  IOS
  ll n,p;
  cin>>n>>p;
  ll c=0;
  while(p%2==0)
  {
    c++;
    p/=2;
  }

  c/=n;
  ll ans=pow(2,c);
  for(ll i=3;i<=sqrt(p);i+=2)
  { 
    ll c=0;
    while(p%i==0)
    {
      p/=i;
      c++;
    }
    c/=n;
    ans=ans*pow(i,c);
  }
  if(p>2)
  {
    if(n==1)
    {
      ans*=p;
    }
  }

  cout<<ans<<endl;



    

}




    

    
 
    
    

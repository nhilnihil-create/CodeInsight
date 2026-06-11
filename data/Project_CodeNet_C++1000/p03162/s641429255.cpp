   //____________________________________________________________________
  //________________________________NAMAN_______________________________
 //________________________________TALAYCHA______________________________
//__________________________________________________________________________

#include <bits/stdc++.h>
#define ll              long long
#define int             long long
#define pmin            priority_queue < ll, vector<ll>, greater<ll> >
#define pmax            priority_queue <ll>
#define endl            '\n'
#define mii             map<ll , ll >
#define pii             pair< ll, ll >
#define vi              vector<ll>
#define all(a)          (a).begin(), (a).end()
#define DEBUG           cerr<<"/n>>>I'm Here<<</n"<<endl;
#define rep(i, a, b )   for (ll i = a; i < b; i++)
#define rrep(i, a, b)   for (ll i = a; i >= b; i--)
#define bs              binary_search
#define present(c, x)   ((c).find(x) != (c).end())
#define cpresent(c, x)  (find(all(c), x) != (c).end())
#define p1(i)           cout<<i<<endl;
#define p2(i,j)         cout<<i<<" "<<j<<endl;
#define line            cout<<endl;
#define prt(s,b,n)      rep(i,(b),(n)) { cout<<(s)[i]<<" ";} line
#define lower(u)        transform(u.begin(), u.end(), u.begin(), ::tolower);  //convert string u to lowercase;
#define upper(u)        transform(u.begin(), u.end(), u.begin(), ::toupper);
#define tr(container, it) \
for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define hell 1e6+3
#define mod 998244353

  using namespace std;

//_________________________________________________________________________________________________________
//__________________________________________START____________________________________________________________

//................EVERY COIN HAS TWO SIDES...............................................................................................................

void solve()
{
  ll n,k; 
  //ll m=0 , mx=0 , mn=0 , k=0 , ans=0 , flag=0 , res=0 ;
  cin>>n;
  //for(ll i=0;i<n;i++)
  //string s;  cin>>s;
 vi a(n);
  vi b(n);
   vi c(n); rep(i,0,n){ cin>>a[i]>>b[i]>>c[i];}

  ll d1[n+1];
  rep(i,0,n+1) d1[i]=INT_MIN;
  d1[0]=0;
  d1[1]=a[0];
  
    ll d2[n+1];
  rep(i,0,n+1) d2[i]=INT_MIN;
  d2[0]=0;
  d2[1]=b[0];

    ll d3[n+1];
  rep(i,0,n+1) d3[i]=INT_MIN;
  d3[0]=0;
  d3[1]=c[0];

  rep(i,2,n+1)
  {  
    d1[i]=max(d2[i-1]+a[i-1],d3[i-1]+a[i-1]);
    d2[i]=max(d1[i-1]+b[i-1],d3[i-1]+b[i-1]);
    d3[i]=max(d2[i-1]+c[i-1],d1[i-1]+c[i-1]);
  }
 // prt(d1,1,n+1)
 // prt(d2,1,n+1)
 // prt(d3,1,n+1)
  cout<<max(d1[n],max(d2[n],d3[n]))<<endl;
  return;
}

//__________________________________________________________________________________________________________
//__________________________________________END______________________________________________________________

signed main() 
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  #ifndef ONLINE_JUDGE 
  freopen("input.txt" , "r", stdin);
  freopen("out12.txt" , "w", stdout);
  #endif  
//sieve();
  ll TESTS = 1;
  //cin>>TESTS;
  while (TESTS--) 
  {
    solve();
  }
  return 0;
}

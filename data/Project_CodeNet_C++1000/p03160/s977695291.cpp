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
  ll n; 
  
  cin>>n;
  //for(ll i=0;i<n;i++)
  //string s;  cin>>s;
 vi a(n); rep(i,0,n){ cin>>a[i];}
  ll d[n+1];
  rep(i,0,n+1) d[i]=INT_MAX;
  d[0]=0;
  d[1]=0;
  d[2]=abs(a[0]-a[1]);
  rep(i,3,n+1)
  {
     d[i]=min(d[i-1]+abs(a[i-1]-a[i-2]),d[i-2]+abs(a[i-1]-a[i-3]));
  }
  cout<<d[n]<<endl;
  return;
}

//__________________________________________________________________________________________________________
//__________________________________________END______________________________________________________________

signed main() 
{

//sieve();
  ll TESTS = 1;
  //cin>>TESTS;
  while (TESTS--) 
  {
    solve();
  }
  return 0;
}

   //____________________________________________________________________
  //________________________________NAMAN_______________________________
 //________________________________TALAYCHA______________________________
//_________________________________________________________________________

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

string ans="";

ll d[3000+1][3000+1];
void dfs(ll i , ll j,string s,string t)
{
  if(d[i][j]==0)
    return;
  if(d[i][j]>d[i-1][j] && d[i][j]>d[i][j-1] && d[i][j]>d[i-1][j-1])
  {
    ans+=s[i-1];
    dfs(i-1,j-1,s,t);
  }
  else if(d[i][j]==d[i-1][j] )
  {
    dfs(i-1,j,s,t);
  }
   else if(d[i][j]==d[i][j-1] )
  {
    dfs(i,j-1,s,t);
  }
  else
    dfs(i-1,j-1,s,t);
}

void solve()
{
  ll n; 

 // ll m=0 , mx=0 , mn=0 , k=0 , ans=0 , flag=0 , res=0 ;
  //cin>>n;
  //for(ll i=0;i<n;i++)
     string t;
    string s;
    cin>>s;
    cin>>t;
   // return ;
  n=s.size();
  ll m=t.size();


  rep(i,0,n+1)
  {
    rep(j,0,m+1)
    {
      if(i==0 || j==0)
      {
        d[i][j]=0;
        continue;
      }
      if(s[i-1]==t[j-1])
      {
        d[i][j]=d[i-1][j-1]+1;
      }
      else
      {
        d[i][j]=max(d[i-1][j-1],max(d[i][j-1],d[i-1][j]));
      }
    }
  }

dfs(n,m,s,t);
reverse(all(ans));
p1(ans)
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

  ll TESTS = 1;
 //  cin>>TESTS;
  while (TESTS--) 
  {
    solve();
  }
  return 0;
}

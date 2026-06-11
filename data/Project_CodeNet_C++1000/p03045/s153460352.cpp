#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define F first
#define S second
#define db double
#define pb push_back
#define rep(i,a,b)  for(ll i=a;i<=b;i++)
#define all(a) a.begin(),a.end()
using namespace std;

 ll mod=1e9 +7;

ll expo(ll base,ll exponent,ll mod){
    ll ans=1;
    while(exponent!=0){
        if(exponent&1) ans=(1LL*ans*base)%mod;
        base=(1LL*base*base)%mod;
        exponent>>=1;
    }
    return ans%mod;
}
 
vector<bool>  prime(90000002,true);
void Sieve() 
{ 
   
    for (int p=2; p*p<=90000001; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=90000001; i += p) 
                prime[i] = false; 
        } 
    } 
}

ll get_val(vector<ll>&ft,ll index)
{
  ll res=0;
  for(;index>=0;index=(index & (index+1))-1)
    res+=ft[index];
  return res;
}

void update(vector<ll>&ft,ll index,ll val)
{
  for(;index<(ll)ft.size();index|=index+1)
    ft[index]+=val;
}

ll mex(vector<ll>&a, ll n)
{
  ll res=0;
  // set<ll>st;
  vector<ll>b(n+1,0);
  for(auto x:a) b[x]++;
    while(res<n && b[res]>0) res++;
  return res;
}

vector<ll> graph[100005];
ll vis[100005];

void func(ll vertex)
{
  vis[vertex]=1;
  for(auto x:graph[vertex])
  {
    if(!vis[x]) func(x);
  }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //   #ifndef ONLINE_JUDGE
    // // for getting input from input.txt
    // freopen("input.txt", "r", stdin);
    // // for writing output to output.txt
    // freopen("output.txt", "w", stdout);
    // #endif
    
    // Sieve();
   ll tests=1;
 // cin>>tests;
  // ll t=1;
    while(tests--)
    {
      ll i,j,n,m,x,y,z;
      cin>>n>>m;
      rep(i,0,n) vis[i]=0;
      rep(i,0,m-1)
      {
        cin>>x>>y>>z;
        graph[x].pb(y);
        graph[y].pb(x);
      }
      ll ans=0;
      rep(i,1,n)
      {
        if(!vis[i])
        {
          ans++;
          func(i);
        }
      }
      cout<<ans;

    }

    return 0;
   }
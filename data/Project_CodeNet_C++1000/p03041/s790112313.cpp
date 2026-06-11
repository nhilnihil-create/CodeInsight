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
      string s,t;
      ll k,n;
      cin>>n>>k;
      cin>>s;
      t=s.substr(k-1,1);
      transform(t.begin(),t.end(),t.begin(),::tolower);
      s=s.substr(0,k-1) + t + s.substr(k,n-k);
      cout<<s;

    }

    return 0;
   }
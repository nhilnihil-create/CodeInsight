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
      string s,t1,t2;
      cin>>s;
      bool flag1=true,flag2=true;
      t1=s.substr(0,2);
      t2=s.substr(2,2);
      if(t1[0]>'1') flag1=false;
      if(t2[0]>'1') flag2=false;
      if(t1[0]=='0' && t1[1]=='0') flag1=false;
      if(t2[0]=='0' && t2[1]=='0') flag2=false;
      if(t1[0]=='1' && t1[1]>'2') flag1=false;
      if(t2[0]=='1' && t2[1]>'2') flag2=false;
      if(flag1 && flag2) cout<<"AMBIGUOUS";
      else if(flag1) cout<<"MMYY";
      else if(flag2) cout<<"YYMM";
      else cout<<"NA";

    }

    return 0;
   }
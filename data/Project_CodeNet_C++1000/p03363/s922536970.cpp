//*******************************By Harry Singh From Phillaur.
#include<bits/stdc++.h>
#define ll long long
#define MAX 1000006
#define MOD 1000000009
#define string_to_any_base(s,base) stoll(s, 0, base);
#define vc vector
// #define mp map<ll,ll> mp;
#define bt(M,value) bitset<M> b(value)
#define S set<ll> s;
#define ST set<string> s;
#define INF 1e15
using namespace std;
set<ll> primes;
vector<pair<ll,ll>> adj[MAX];
vector<ll> ad[MAX];
///******************************ALL important functions;
ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b);} 
ll lcm(ll a, ll b)  {  return (a*b)/gcd(a, b);  } 
ll power(ll x,ll y){ ll res = 1;x = x % MOD; if (x == 0) return 0;while (y > 0){if (y & 1)  res = ((res%MOD)*(x%MOD)) % MOD;  y = y>>1; x = ((x%MOD)*(x%MOD)) % MOD;  }  return res;  }  
void Sieve(){ bool prime[MAX+1]; memset(prime, true, sizeof(prime)); for (int p=2; p*p<=MAX; p++) { if (prime[p] == true) {for (int i=p*p; i<=MAX; i += p) prime[i] = false; } } for(int i=2;i<=MAX;i++)if(prime[i]==true)primes.insert(i);} 

int main()
{
ll n;cin>>n;
ll a[n+1];
map<ll,ll> mp;
ll pre[200006]={0};
for(int i=1;i<=n;i++){cin>>a[i];}
ll count=0;
mp[0]=1;
ll sum=0;
for(int i=1;i<=n;i++)
{
sum+=a[i];
count+=mp[sum];
mp[sum]++;
	
}
cout<<count<<endl;






}
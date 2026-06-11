#include "bits/stdc++.h"
using namespace std;
#define pb          push_back
#define mp          make_pair
#define pii         pair<ll,ll>
#define vi          vector<ll>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define rev(i,a,b)  for(int i=a;i>=b;i--)
#define ll          long long
#define bg(i)       i.begin()
#define fset(it,s)   for(auto it = s.begin(); it != s.end(); it++)
#define track(x)                cerr<<#x<<": "<<x<<endl
#define track2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define track3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define track4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define ed(i)       i.end()
#define mem(a)      memset(a, 0, sizeof(a))
#define MOD         1000000007
ll mult(ll a,ll b, ll p=MOD){return ((a%p)*(b%p))%p;}
ll add(ll a, ll b, ll p=MOD){return (a%p + b%p)%p;}
ll fpow(ll n, ll k, ll p = MOD) {ll r = 1; for (; k; k >>= 1LL) {if (k & 1LL) r = mult(r,n,p); n = mult(n,n,p);} return r;}
ll inv(ll a, ll p = MOD) {return fpow(a, p - 2, p);}
void self_max(int &a, int &b) {a = max(a, b); }
void self_min(int &a, int &b) {a = min(a, b); }
#define hell        1000000007
bool isPrime(long int n) 
{
    // Corner cases 
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
  
    // This is checked so that we can skip 
    // middle five numbers in below loop 
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
  
    for (int i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
  
    return true; 
}


ll power(int x, unsigned int y, int p) 
{ 
    ll res = 1;      // Initialize result 
  
    x = x % p;  // Update x if it is more than or  
                // equal to p 
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
        // y must be even now 
        y = y>>1; // y = y/2
        x = (x*x) % p;  
    } 
    return res;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ll computeXOR(ll n) 
{ 

  
    switch(n & 3) // n % 4  
    { 
    case 0: return n;     // if n is multiple of 4 
    case 1: return 1;     // If n % 4 gives remainder 1   
    case 2: return n + 1; // If n % 4 gives remainder 2     
    case 3: return 0;     // If n % 4 gives remainder 3   
    } 
}
void solve(){
	ll a, b;
	cin >> a >> b;
	if(a != 0)	a--;
	cout << (computeXOR(b) ^ computeXOR(a)) << endl;

}
int main() {
	// freopen("input.txt", "rt", stdin);
	// freopen("output.txt", "wt", stdout);
    ios::sync_with_stdio(false);
    cout<<fixed<<setprecision(20);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
}


#include<bits/stdc++.h>
//#include<boost/multiprecision/cpp_int.hpp>
#include <chrono>
#define MOD 1000000007
#define debug(x) cout<<"x :"<<x<<endl;
//#define case(t,ans) cout<<"Case #"<<t<<": "<<ans<<endl;
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define for_it(it,s) for (auto it = s.begin(); it != s.end(); it++)
#define for_each(r,s) for(auto r:s)

#define all(s) s.begin(),s.end()
#define rall(s) s.end(),s.begin()
#define F first
#define S second
#define PB push_back
#define pb pop_back
#define EB emplace_back
#define pf push_front

#define fill0(arr) memset(arr,0,sizeof(arr))
#define filln(arr) memset(arr,-1,sizeof(arr))
#define MP make_pair
#define vi vector<int>
#define vll vector<ll>
#define vf vector<float>
#define vd vector<ld>
#define precision(x) cout<<fixed<<setprecision((x));
 

#define fbcase(t) cout << "Case #" << t << ": ";
#define pi pair<int,int> 
#define ll long long 
#define ld long double
#define endl "\n"
//typedef long long ll;
//typedef vector<int> vi;
//typedef pair<int,int> pi;
//sort(a, a+n);
//reverse(a, a+n);
//random_shuffle(a, a+n);

const ll mod=1e9 + 7;
const ll mod1=998244353;



# define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
# define trace1(x)                cerr << #x << ": " << x << "\n";
# define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << "\n";
# define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << "\n";
# define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << "\n";


#define case(i) cout<<"Case "<<i<<": ";



//using namespace boost::multiprecision;
using namespace std;
using namespace std::chrono;

// TC;-  O(log(min(a,b))) SC;-O(1)
long long gcd (long long  a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

// TC;-  O(log(min(a,b))) SC;-O(1)
ll lcm (ll a, ll b) {
    return a / gcd(a, b) * b;
} 


// TC :- O(log(n)) SC;-O(1)
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}


// TC :- O(log(n)) SC;-O(1)       modulo binpow
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
int C(int n, int k) {
    double res = 1;
    for (int i = 1; i <= k; ++i)
        res = res * (n - k + i) / i;
    return (int)(res + 0.01);
}

//  TC;-O(plogpn)
int factmod(int n, int p) {
    int res = 1;
    while (n > 1) {
        res = (res * ((n/p) % 2 ?  p-1 : 1)) % p;
        for (int i = 2; i <= n%p; ++i)
            res = (res * i) % p;
        n /= p;
    }
    return res % p;
}

// TC: O(n) SC:O(1)
bool isPalindrome(string s)
{
    ll l=s.length();
    for(int i=0;i<l/2;i++)
    {
        if(s[i]!=s[l-i-1])
        {
            return false;
        }
    }
    return true;
}

string prefix_function(string s) {
    int n = (int)s.length();
    string piiii;
    for (int i = 0; i < n; i++)
        for (int k = 0; k <= i; k++)
            if (s.substr(0, k) == s.substr(i-k+1, k))
                piiii.push_back(k);
    return piiii;
}

long long computeXOR(long long  n) 
{ 
    // Modulus operator are expensive on most of the  
    // computers. n & 3 will be equivalent to n % 4.    
  
    switch(n & 3) // n % 4  
    { 
    case 0: return n;     // if n is multiple of 4 
    case 1: return 1;     // If n % 4 gives remainder 1   
    case 2: return n + 1; // If n % 4 gives remainder 2     
    case 3: return 0;     // If n % 4 gives remainder 3   
    } 
    return -1;
} 
  
bool isPrime(int n)
{
    for(int i=2;i*i<n;i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}

int sumOfDigits(ll n)
{
    int sum = 0;
    while(n>0)
    {
        int r = n%10;
        sum += r;
        n = n/10;
    }
    return sum;
}
int sumOfDigits(int n)
{
    int sum = 0;
    while(n>0)
    {
        int r = n%10;
        sum += r;
        n = n/10;
    }
    return sum;
}

bool visited[100005];
vector<int> ans(100005,0);
vector<pair<int,int>> adj[100005];
void dfs(int source,int parent);
void solve();
int main(){


    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1;
    //cin>>t;
   // clock_t launch=clock();
    //   clock_t start, end;
    //   start = clock();
    auto start = chrono::high_resolution_clock::now();
    for(ll i=1;i<=t;i++)
    {
       // case(i);
        solve();
    }
    auto end = chrono::high_resolution_clock::now();

    double time_taken =  
      chrono::duration_cast<chrono::nanoseconds>(end - start).count(); 
  
    time_taken *= 1e-9; 
  
    cerr  << "Time taken by program is : " << fixed  
       << setprecision(10)  << time_taken ; 
    cerr << " sec" << endl;
   // end = clock();

  // Calculating total time taken by the program. 
  //  double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
    //cerr << "Time taken by program on this test cases is : " << fixed  
    //    << setprecision(64) << time_taken ; 
    //cerr << " sec " << endl;  
   //  clog<<((long double)(clock()-launch)/CLOCKS_PER_SEC)<<"\n";
   //  cerr<<"error is good"<<endl;
    return 0;
}
void dfs(int source , int parent)
{
    //if(source == parent) return;
    //if(visited[source]) return;
    visited[source] = true;
    for(auto i:adj[source])
    {
        if(!visited[i.first])
        {
            if(i.second % 2 == 0)
            {
                ans[i.first] = 0^ans[source];
            }
            else
            {
                ans[i.first] = 1^ans[source];
            }

            dfs(i.first,source);
        }
        

    }
}
void solve()
{
    ll t = 1;
    //cin >> t;
    while(t--)
    {
        
        int n;
        cin >> n;
        
         // vertices and weight;
        for(int i=0;i<n - 1;i++)
        {
            int u,v,w;
            cin >> u >> v >> w;
            u--;
            v--;
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        memset(visited,false,sizeof(visited));
        ans[0] = 0;
        dfs(0, - 1);

        for(int i=0;i<n;i++)
        {
            cout << ans[i] << endl;
        }

    }

}

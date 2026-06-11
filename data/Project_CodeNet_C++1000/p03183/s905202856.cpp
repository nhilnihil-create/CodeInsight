/*
मनस्वी म्रियते कामं कार्पण्यं न तु गच्छति ।
अपि निर्वाणमायाति नानलो याति शीतताम् ॥
*/

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds;
using namespace std;
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define ll long long int
#define ld long double
#define vi vector<int>
#define vl vector<ll>
#define v2i vector<vector<int>>
#define v2l vector<vector<ll>>
#define ppi pair<int,int>
#define ppl pair<ll,ll>
#define vpi vector<ppi>
#define vpl vector<ppl>
#define all(x) x.begin(),x.end()
#define ii int,int 
#define ff first    
#define ss second
#define forn(i,a,b) for(int i=a;i<b;i++)
#define forr(i,a,b) for(int i=a;i>=b;i--)
#define forv(i,m) for(auto i : m)
#define p2d(v) for(auto a:v){for(auto b:a)cout<<b<<" ";cout<<endl;}
#define p1d(v) for(auto a:v)cout<<a<<" ";cout<<endl;
#define ppd(v) for(auto a:v)cout<<a.ff<<" "<<a.ss<<endl;
#define imx INT_MAX
#define imn INT_MIN
#define inf 9000000000000000000
#define minf -inf
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define sze size()
#define rvs reverse 
#define itr iterator 
#define pre cout<<fixed<<setprecision(10);
#define umap unordered_map
#define uset unordered_set
#define pi 3.141592653589793
#define MAXN 100005
#define test1(x) cout << #x " = " << x << endl;
#define test2(x,y) cout << #x " = " << x << " " << #y " = " << y << endl;
#define test3(x,y,z) cout << #x " = " << x << " " << #y " = " << y << " " << #z " = " << z << endl;
#define test4(w,x,y,z) cout << #w " = " << w << " " << #x " = " << x << " " << #y " = " << y << " " << #z " = " << z << endl;
const ll infinity = 9e18;

/*
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define MODM(a,b,md) ((a%md)*(b%md))%md
#define MODA(a,b,md) ((a%md)+(b%md))%md
#define ull unsigned long long int
*/

/*
bool compare(int a,int b) {return a > b;}
bool compare1(ppi a,ppi b) {return a.ff > b.ff;}
bool compare2(ppi a,ppi b) {return a.ss < b.ss;}
ll Npower(ll a,ll b) {ll product = 1; while(b){if(b&1){product = product*a;}a = a*a;b = b>>1;} return product;}
ll power(ll a,ll b,ll md) {ll product = 1; while(b){if(b&1){product = MODM(product,a,md);}a = MODM(a,a,md);b = b>>1;} return product%md;}
bool isprime(ll n){if(n < 2) return 0; ll i = 2; while(i*i <= n){if(n%i == 0) return 0; i++;} return 1;}
ll GCD(ll a,ll b) {return b==0 ? a:GCD(b,a%b);}
ll LCM(ll a,ll b) {return (a/GCD(a,b))*b; }
*/

ll n;

v2l v;

bool compare(vl a,vl b)
{
    if(a[1]+a[0] == (b[1]+b[0]))
    {
        return a[2] > b[2];
    }
    return (a[1]+a[0]) < (b[1]+b[0]);
}

ll dp[1005][10005] = {};

ll func(ll idx,ll sum)
{
    if(idx == n) return 0;

    if(sum > 10000) return 0;

    if(dp[idx][sum] != -1)
    {
        return dp[idx][sum];
    }

    ll ans = 0;

    if(sum <= v[idx][1])
    {
        ans = ans + max(v[idx][2]+func(idx+1,sum+v[idx][0]),func(idx+1,sum));
    }
    else
    {
        ans = ans + func(idx+1,sum);
    }

    return dp[idx][sum] = ans;
}

int main()
{
    fast

/*
    #ifndef ONLINE_JUDGE
        freopen("input.txt",  "r",  stdin);
        freopen("output.txt", "w", stdout);
    #endif
//*/

    cin>>n;
        
    v.resize(n,vl(3,0));

    forn(i,0,n)
    {
        forn(j,0,3)
        {
            cin>>v[i][j];
        }
    }
    
    // p2d(v)    
        
    sort(all(v),compare);

    memset(dp,-1,sizeof(dp));

    cout<<func(0,0);


    return 0;
}
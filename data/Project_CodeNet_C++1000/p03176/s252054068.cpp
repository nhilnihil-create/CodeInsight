#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>  
#include <ext/pb_ds/tree_policy.hpp>   
using namespace std;
using namespace __gnu_pbds;  
typedef tree<int, null_type, less<int>, rb_tree_tag,  tree_order_statistics_node_update>  ordered_set; 
#define num 1000000007
//#define num 998244353
#define REP(i,a,n) for(ll i=a;i<n;i++)
#define inarr(i,a,n,A) for(ll i=a;i<n;i++) { cin>>A[i]; }
#define vll vector<long long>
#define pii pair <int,int>
#define pll pair<long long, long long>
#define vpii vector< pair <int,int>>
#define vpll vector< pair<long long, long long>>
#define avg(a,b) ((a)+(b))/2
#define pb push_back
#define pob pop_back
#define sf int flag=0     //Remember semicolon
#define assmin(a,b) if(b<=a) { a=b; }
#define assmax(a,b) if(b>=a) { a=b; }
#define f first
#define s second
#define fix(f,n) std::fixed<<std::setprecision(n)<<f
#define all(x) x.begin(), x.end()
#define M_PI 3.14159265358979323846
#define epsilon (long double)(0.00000000001)
#define side 1e9
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;

ll mod(ll a, ll b)
{
	if(a%b<0)
	{
		return a%b + b;
	}
	return a%b;
}
 
 
ll mod_exp(ll a, ll b, ll c)
{
	ll res=1;
	a=a%c;
	while(b>0)
	{
		if(b%2==1)
		{
			res=(res*a)%c;
		}
		b/=2;
		a=(a*a)%c;
	}
	return res;
}
ll mymod(ll a,ll b)
{
    return ((a%b)+b)%b;
}
bool prime[200001];
void SieveOfEratosthenes() 
{ 
    memset(prime, true, sizeof(prime)); 
    prime[1]=false;
    for (int p=2; p*p<=200000; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=200000; i += p) 
                prime[i] = false; 
        } 
    } 
    return;
}
ll powe[100005];
void power()
{
    powe[0]=1;
    REP(i,1,100005)
    {
        powe[i]=mymod(2*powe[i-1],num);
    }
}
ll gcdExtended(ll,ll,ll *,ll *);
ll modInverse(ll a, ll m) 
{ 
    ll x, y; 
    ll g = gcdExtended(a, m, &x, &y); 
    g++;   //this line was added just to remove compiler warning
    ll res = (x%m + m) % m;
    return res;
} 
ll gcdExtended(ll a, ll b, ll *x, ll *y) 
{ 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
    ll x1, y1; 
    ll gcd = gcdExtended(b%a, a, &x1, &y1);
    *x = y1 - (b/a) * x1; 
    *y = x1; 
    return gcd; 
}
struct node
{
	vll adj;
};
ll segtree[525000]={0};
ll query(ll v, ll left, ll right, ll l, ll r)
{
    if(l>r)
    {
        return 0;
    }
    if(left==l && right==r)
    {
        return segtree[v];
    }
    ll mid = (left+right)/2;
    ll a = query(2*v, left, mid, l, min(r,mid));
    ll b = query(2*v+1, mid+1, right, max(l,mid+1), r);
    return max(a,b);
}
void update(ll v, ll left, ll right, ll pos, ll value)
{
    if(left==right)
    {
        if(segtree[v]>value)
        {
            return;
        }
        else
        {
            segtree[v] = value;
            return;
        }
    }
    ll mid = (left+right)/2;
    if(mid>=pos)
    {
        update(2*v, left, mid, pos, value);
    }
    else
    {
        update(2*v+1, mid+1, right, pos, value);
    }
    segtree[v] = max(segtree[2*v], segtree[2*v+1]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    vpll flower(n);
    REP(i,0,n)
    {
        cin>>flower[i].f;
    }
    REP(i,0,n)
    {
        cin>>flower[i].s;
    }
    vll dp(n+1, 0);   // dp[i] : solution for problem if only first i flowers were there
    dp[0] = 0;
    REP(i,1,n+1)
    {
        dp[i] = dp[i-1];
        ll x = query(1,1,n,1,flower[i-1].first-1);
        dp[i] = max(dp[i], flower[i-1].second+x);
        update(1,1,n,flower[i-1].first,flower[i-1].second+x);
    }
    cout<<dp[n]<<"\n";
    return 0;
}



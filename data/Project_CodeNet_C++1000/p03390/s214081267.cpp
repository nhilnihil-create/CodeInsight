#include "bits/stdc++.h"
#include <chrono>
#include <random>
#include <cstdio>
#define ll long long int
#define endl '\n'
#define pb push_back
#define mp make_pair
// #define mod 998244353
#define rep(i,n) for(ll i=0;i<n;i++)
#define vi vector <int>
#define vs vector <string>
#define vc vector <char>
#define vl vector <ll>
#define pll pair<ll, ll>
#define pint pair<int, int>
#define S second
#define F first
#define all(c) (c).begin(),(c).end()
using namespace std;
// ll power(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// ll modInverse(ll a){return power(a,mod-2);}
const int N=500001;
// vector<pair<ll, ll> > adj[N];
// bool vis[N];
ll gcd(ll a, ll b) { if (a == 0) return b; return gcd(b % a, a); } 
ll lcm(ll a, ll b){return a*b/gcd(a, b);}
#define pi 3.14159265358979323846264338
using namespace std; 
ll max(ll a, ll b){ if(a>b)return a;return b;}
ll min(ll a, ll b){ if(a < b) return a;return b;}
ll inf = 100000000000000000;
vector <int> adj[N];


void solve() 
{
    ll a, b;
    cin>>a>>b;

    if(a > b) swap(a, b);

    if(a == b)
    {
        cout<<2*a - 2<<endl;
    }
    else if(a + 1 == b)
    {
        cout<<2*a - 2<<endl;
    }
    else
    {
        ll c =sqrt(a*b);
        if(c*c == a*b) c--;

        if(c*(c+1) >= a*b)
        {
            cout<<2*c - 2<<endl;
        }
        else
        {
            cout<<2*c - 1<<endl;
        }
    }

} 

int main()
{
    #ifndef ONLINE_JUDGE
        // for getting input from input.txt
        freopen("input.txt", "r", stdin);
        // for writing output to output.txt
        freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;
    cin>>T;
    int t=0;
    while(t++<T)
    {
        // cout<<"Case #"<<t<<":"<<' ';
        solve();
        // cout<<'\n';
    }

    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}
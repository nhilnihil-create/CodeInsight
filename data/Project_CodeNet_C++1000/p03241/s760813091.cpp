#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long
#define bp  __builtin_popcount
#define pb push_back
#define sz(s) (int)(s.size())
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define Unique(n)        (n).erase(unique(all(n)), (n).end())
#define NumofDigits(n)   ((long long)log10(n)+1)
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
const int maxn=1e5+5;
const  double EPS = 1e-9;
const int mod = 1e9+7;
/*
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
ll fastpow(ll b, ll p)
{if(!p)return 1;ll ret = fastpow(b, p >> 1);ret *= ret;if(p&1)ret*= b;return ret;}
*/
int dx[] = { -1,-1,-1,0,+1,+1,+1,0 };   // direction array
int dy[] = { -1,0,+1,+1,+1,0,-1,-1 };


int main()
{
    ios::sync_with_stdio(0);
/*#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    clock_t START_TIME = clock();
#endif*/
    ll n,m;
    cin>>n>>m;
    ll d=m/n;
    for(ll i=d;i>=1;i--)
        if(m%i==0)
         return cout<<i,0;
/*#ifndef ONLINE_JUDGE
    cout << endl << "// Time taken = " << fixed << setprecision(5) << (clock() - START_TIME) * 1e3 / CLOCKS_PER_SEC << " ms";
#endif*/
}

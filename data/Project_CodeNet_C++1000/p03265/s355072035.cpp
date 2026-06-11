#include <bits/stdc++.h>
using namespace std;
#define gcd(m,n) __gcd(m,n)
#define lcm(m,n) m*(n/gcd(m,n))
#define fast std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pi acos(-1.0)
#define endl '\n'
#define MOD 1000000007
#define ull unsigned long long
#define ll long long
#define ld long double
#define pb push_back
#define dbg(x) cout << #x << "  " << x << endl;
 
ll power(ll base, ll exp) 
{ll res=1;while(exp>0) {if(exp%2==1) res=(res*base);base=(base*base);exp/=2;}return res;}
ll mod(ll a, ll b) {return (a % b + b) % b;}
ll powerm(ll base,ll exp,ll mod) 
{ll ans=1;while(exp){if(exp&1) ans=(ans*base)%mod;exp>>=1,base=(base*base)%mod;}return ans;}
/*{{ x | (1 << k) sets the kth bit of x to one
x & ~(1 << k) sets the kth bit of x to zero
x ^ (1 << k) inverts the kth bit of x.
x & (x-1) sets the last one bit of x to zero
x & -x sets all the one bits to zero, except for the last one bit. 
x | (x-1) inverts all the bits after the last one bit.}} SOME BIT MANIPULATION*/
//__builtin_clz(x): the number of zeros at the beginning of the number
//__builtin_ctz(x): the number of zeros at the end of the number
//__builtin_popcount(x): the number of ones in the number
//__builtin_parity(x): the parity (even or odd) of the number of ones 
struct custom_hash 
{
    static uint64_t splitmix64(uint64_t x) 
	{
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const 
	{
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
/*//DSU 
int parent[200005];
int rankr[200005];
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void make_set(int v) {
    parent[v] = v;
    rankr[v] = 0;
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rankr[a] < rankr[b])
            swap(a, b);
        parent[b] = a;
        if (rankr[a] == rankr[b])
            rankr[a]++;
    }
} */

int main()
{  
	fast; 
	ll x1,x2,y1,y2; cin>>x1>>y1>>x2>>y2;
	ll x = x2 - x1; ll y = y2 - y1; 
	cout << x2 - y << " " << y2 + x <<  " " << x1 - y << " " << y1 + x << endl;
	return 0;
}
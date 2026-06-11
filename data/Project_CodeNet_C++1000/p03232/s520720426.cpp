/**
 *    Author:  "Robin Singh" !!!
 *    BrainyIsTheNewSexy     (CodeForces)
 *    rob_in_1               (Other OJs)
**/
#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define IO  freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(),(x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())
#define ff first
#define ss second
#define mp make_pair
#define szz(v) ((int)(v).size())  
#define fr(i, j, k) for(int i = j; i < k; i++)     
#define bk(i, j, k) for(int i = j-1; i >= k; i--)
#define mem(ptr)  memset(ptr, 0, sizeof ptr)
#define sbit(n)  __builtin_popcount(n)
#define nl "\n"
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector <int> vi;
typedef vector <long long> vll;
typedef vector < pair<int,int> > vpii;
typedef vector < pair<ll, ll> > vpll;

//---------------------------------------------*DEBUGGING*--------------------------------------------------------->]
#define dbg( args...) { vector<string> _v = split( #args, ','); err( _v.begin(), args); cerr << '\n'; }
vector<string> split( const string& s, char c) { vector<string> v; stringstream ss( s); string x; 
while ( getline( ss, x, c)) v.emplace_back(x); return move(v); }
void err( vector<string>::iterator it) { } 
template<typename T, typename... Args>
void err( vector<string>::iterator it, T a, Args... args) {
    cerr << it -> substr( ( *it)[0] == ' ', it -> length()) << " = " << a << '\t'; err( ++it, args...); }
//----------------------------------------------------------------------------------------------------------------->]
//*****************************************!Template Ends Here!*****************************************************]

const long long mod = 1e9+7;
const long double eps = 1e-9;
const long long INF = (1LL<<61);
const int inf = (1<<30);
const int nn = 1e5+5;

ll expo(ll n, ll m){
    ll res = 1;
    n %= mod;
    while(m){
        if(m & 1) res = res * n % mod;
        n = n * n % mod;
        m >>= 1;
    }
    return res;
}

ll nf, inv[nn], pref[nn];

void precompute(int n){
    nf = 1;
    for(int i=2; i <= n; i++){
        nf = nf * i % mod;
    }

    for(int i=1; i <= n; i++){
        inv[i] = nf * expo(i, mod-2) % mod;
    }

    for(int i=2; i<=n; i++){
        pref[i] = (pref[i-1] + inv[i] ) % mod;
    }

}

int main()
{
    //IO;
    IOS;
    int n;
    cin >> n;

    precompute(n);
    
    ll ans = 0;
    for(int i=1; i<=n; i++){
        ll x;
        cin >> x;
        ll cnt = nf;
        cnt = (cnt + pref[i]) % mod;
        cnt = (cnt + pref[n-i+1]) % mod;
        cnt = cnt * x % mod;

        ans = (ans + cnt) % mod;
    }
    cout << ans;
    return 0;
}

/*
Basic idea is this: fix two specific elements i and j. 
The cost for removing block j will include the weight of i if and only if j is removed first
out of the blocks in the section i through j.
If not, i will be disconnected from j (or won't be present at all) by the time j is removed.

The number of permutations in which j is removed first among the blocks in i through j is N! / (j — i + 1).
That's because there's N! total permutations, there are j — i + 1 blocks in that section, 
and by symmetry each of the blocks appears first in the same number of permutations.

By precomputing N! / k we get an O(N^2) solution.
See ith element contribution for each j.
It can be speed up to O(N); (precomputing along with pref sum of interval )
Interval of each i ---> (1..., i) or (i, ... N)
(i, i) count will be twice in pref[i] and pref[n-i+1], so count it once manually anf take pref[1] = 0
*/

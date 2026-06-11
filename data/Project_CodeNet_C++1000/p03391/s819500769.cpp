#include "bits/stdc++.h"
#include <stdint.h>

#pragma optimize("O3")

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

#define sync                    \
ios_base::sync_with_stdio(0); \
cin.tie(0);                   \
cout.tie(0)
#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define pb push_back
#define mp make_pair
#define fopen freopen("input.txt", "r", stdin); freopen("output.txt","w", stdout)
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define FORR(i, b, a) for(ll i = (b) - 1; i >= (a); --i)
#define REP(i, N) FOR(i, 0, N)
#define REPR(i, N) RFOR(i, N, 0)
#define FILL(A,value) memset(A,value,sizeof(A))
#define ff first
#define ss second
#define pii pair<int,int>
#define pll pair<ll, ll>
#define MP make_pair
#define endl '\n'

const ll MOD = 1e9 + 7;
const ll INF = 2*1e9 + 7;
const int base = 2e5+1;
const int MAX =1e5+2;
const double EPS = 1e-9;
const double PI = acos(-1.);
const int MAXN = 2*1e5+1;




int main()
{
    int n;
    cin >> n;
    ull sum = 0;
    bool ok = 1;
    ull x = INF;
    FOR(i,0,n)
    {
        ull a, b;
        cin >> a >> b;
        if(a!=b)
        {
            ok = 0;

        }
        if(a > b)
        {
            x = min(x, b);
        }
        sum += a;
    }

    if(ok) cout << 0;
    else cout << sum - x;
    return 0;
}



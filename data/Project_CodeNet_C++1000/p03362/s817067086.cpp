#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define min_3(a,b,c) min(a,min(b,c))
#define max_3(a,b,c) max(a,max(b,c))
#define nout(ans) cout << (ans) << "\n"
#define sout(ans) cout << (ans) << " "
using namespace std;

const double pi = 3.14159265359;
const ll INF = 1e12;
const ll MOD = 1e9 + 7;
const ll N = 3005; 
/*
Decimal Places: cout << fixed << setprecision(n) << ans << endl
*/

bool compare(const pair<int, int>&i, const pair<int, int>&j)
{
    return i.second < j.second;
}

ll raise(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}


bool sieve[N]; int n, ans=0;

void solve()
{
    fill(sieve,sieve+N,true);
    sieve[0]=sieve[1]=false;
    for (int i=2; i<=N; i++) {
        if (sieve[i] && i*i<=N) {
            for (int j=i*i; j<=N; j+=i) sieve[j] = false;
        }
    }

    cin >> n;
    int i=11;
    while (n>0) {
        if (sieve[i]) {
            sout(i); n--;
        }i+=10;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t = 1;
    //cin >> t;
    for (int i=1; i<=t; i++)
    {
        solve();
    }
    return 0;
}
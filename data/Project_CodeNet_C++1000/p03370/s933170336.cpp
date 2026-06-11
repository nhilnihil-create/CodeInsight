#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define ld long double
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int, int>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define sws ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
#define teto(a, b) ((a+b-1)/(b))
using namespace std;

const int MAX = 100010;
const int MOD = 1000000007;
const int INF = (int)1e9;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const ld EPS = 1e-7;

// Extra
#define forn(i, n) for(int i = 0; i < (int)n; i++)
#define forne(i, a, b) for(int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()
#define dbg(msg, var) cout << msg << " " << var << endl;
#define ti tuple<int,int,int>
//

int main() {
    int n, x;
    cin >> n >> x;

    int res = 0;
    vi v(n);
    forn(i, n) {
        cin >> v[i];
    }

    sort(all(v));
    forn(i, n) {
        if(v[i] <= x) {
            x -= v[i];
            res++;
        }
    }

    while(v[0] <= x) {
        x -= v[0];
        res++;
    }

    cout << res << endl;


    return 0;
}

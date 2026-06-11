#include <bits/stdc++.h>
#define itn int
#define REP(i, n) for (ll i = 0; i < n; i++)
#define IREP(i, n) for (ll i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (ll i = a; i < b + 1; i++)
#define all(v) v.begin(), v.end()
#define SENTINEL 2000000000
#define NIL -1
using namespace std;
typedef long long ll;

const ll INF = 1LL << 60;
const ll MOD = 1000000007;
template <class T>inline bool chmin(T &a, T b){if(a>b){a=b;return true;}return false;}
template <class T>inline bool chmax(T &a, T b){if(a<b){a=b;return true;}return false;}

int main()
{
    ll n,m,d;
    cin >> n >> m >> d;
    if(d==0){
        long double ans=m-1;
        ans/=n;
        cout << fixed << setprecision(10);
        cout << ans << endl; 
    }
    else{
        long double ans=2*(n-d)*(m-1);
        ans/=n*n;
        cout << fixed << setprecision(10);
        cout << ans << endl;
    }
}
#include <bits/stdc++.h>
#define itn int
#define REP(i, n) for (ll i = 0; i < n; i++)
#define IREP(i, n) for (ll i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define all(v) v.begin(), v.end()
#define SENTINEL 2000000000
#define NIL -1
using namespace std;
typedef long long ll;

const ll MAX = 510000;
const ll INF = 1LL << 60;
const ll MOD = 1000000007;
template <class T>inline bool chmin(T &a, T b){if(a>b){a=b;return true;}return false;}
template <class T>inline bool chmax(T &a, T b){if(a<b){a=b;return true;}return false;}

int main()
{
    ll n;
    cin >> n;
    if(n%2==0){
        cout << n*(n-2)/2 << endl;
        REP(i,n){
            ll k=i+1;
            FOR(j,i+1,n){
                if(k+j+1==n+1){
                    continue;
                }
                cout << k << " " << j+1 << endl;
            }
        }
    }
    else{
        cout << n-1+(n-3)*(n-1)/2 << endl;
        REP(i,n-1){
            ll k=i+1;
            FOR(j,i+1,n){
                if(k+j+1==n){
                    continue;
                }
                cout << k << " " << j+1 << endl;
            }
        }
    }
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp setprecision
#define pb(x) push_back(x)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ld, ld> pdd;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = 1e8;
const ll INF = 1e16;
const string alpha = "abcdefghijklmnopqrstuvwxyz";

int main(){
    int Q;
    cin >> Q;
    rep(j, Q){
        ll A[2];
        cin >> A[0] >> A[1];
        ll l[2], r[2];
        rep(i, 2){
            l[i] = 0, r[i] = A[i];
            while(r[i]-l[i] > 1){
                ll n = (l[i]+r[i])/2;
                bool able = true;
                if(n >= A[i^1]+1){
                    ll x = n+A[i^1]+1;
                    if((x/2) * ((x+1)/2) >= A[0]*A[1]) able = false;
                }
                else{
                    if(n*(A[i^1]+1) >= A[0]*A[1]) able = false;
                }
                if(able) l[i] = n;
                else r[i] = n;
            }
        }
        cout << min(A[0]+l[1], A[1]+l[0]) -1 << endl;
    }
}
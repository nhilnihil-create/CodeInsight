#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define rep(i, n) for(ll i=0; i<(ll)(n); i++)
#define repd(i, n) for(ll i=n-1; 0<=i; i--)
#define FOR(i, a, b) for(ll i=a; i<(ll)(b); i++)
#define FORD(i, a, b) for(ll i=b-1; (ll)(a)<=i; i--)
#define ALL(x) x.begin(), x.end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
string YES[2] = {"NO", "YES"};
string yes[2] = {"No", "Yes"};

int main(){
    ll n;   cin >> n;
    vector<ll> a(n);
    rep(i, n)   cin >> a[i];
    ll res=0;
    rep(i, n-1){
        if(a[i]+1<a[i+1]) res = -1;
    }
    if(a[0]>0) res = -1;
    if(!res){
        res += a[0];
        rep(i, n-1){
            if(0<a[i+1] && a[i+1]<=a[i]) res += a[i+1]-1;
            if(0<a[i+1]) res += 1;
            //cout << a[i+1] << ' ';
        }
    }
    cout <<res << endl;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1'000'000'007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define rep(i, n) for(ll i=0; i<(ll)(n); i++)
#define repd(i, n) for(ll i=n-1; 0<=i; i--)
#define FOR(i, a, b) for(ll i=a; i<(ll)(b); i++)
#define FORD(i, a, b) for(ll i=a-1; (ll)(b)<=i; i--)
#define ALL(x) x.begin(), x.end()
#define rALL(x) x.rbegin(), x.rend()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

vector<vector<char>> g;
int main(){
    ll n;   cin >> n;
    char key[5] = {'M', 'A', 'R', 'C', 'H'};
    vector<ll> cnt(5);
    rep(i, n){
        string s;   cin >> s;
        rep(i, 5) if(s[0]==key[i]) cnt[i] += 1;
    }
    ll res=0;
    rep(i, 5){
        FOR(j, i+1, 5){
            FOR(k, j+1, 5) res += cnt[i]*cnt[j]*cnt[k];
        }
    }
    cout << res << endl;
    
}

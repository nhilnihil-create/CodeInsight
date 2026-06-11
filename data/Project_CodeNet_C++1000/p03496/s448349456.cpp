#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < n; i++)
#define REPR(i, n) for(ll i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(ll i = m; i <= n; i++)
#define FORR(i, m, n) for(ll i = m; i >= n; i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define VSORTR(v) sort(v.rbegin(), v.rend());
#define ALL(v) (v).begin(),(v).end()
 
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;

int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    vll a(n);
    ll ma = -1e10, mi = 1e10, mapos, mipos;
    REP(i, n){
        cin >> a[i];
        if(a[i] > ma){
            ma = a[i];
            mapos = i;
        }
        if(a[i] < mi){
            mi = a[i];
            mipos = i;
        }
    }
    cout << 2 * n - 2 << endl;
    if(abs(ma) > abs(mi)){
        REP(i, n){
            if(i != mapos) cout << mapos + 1 << " " << i + 1 << endl;
        }
        REP(i, n - 1){
            cout << i + 1 << " " << i + 2 << endl;
        }
    }
    else{
        REP(i, n){
            if(i != mipos) cout << mipos + 1 << " " << i + 1 << endl;
        }
        REPR(i, n - 1){
            cout << i + 2 << " " << i + 1 << endl;
        }
    }
    return 0;
}
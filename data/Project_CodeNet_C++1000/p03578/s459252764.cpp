#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 1e9
#define ALL(v) v.begin(), v.end()

using namespace std;
typedef long long ll;

int main(){
    ll n, m;
    cin >> n;
    vector<ll>d(n, 0);
    REP(i, n) cin >> d[i];

    cin >> m;
    vector<ll>t(m, 0);
    REP(i, m) cin >> t[i];

    sort(ALL(d));
    sort(ALL(t));

    int curr = 0;

    REP(i, n){
        if (d[i] == t[curr]){
            curr++;
        }
    }
    if (curr == m){
        cout << "YES" << endl;
        return 0;
    }
    
    cout << "NO" << endl;
    return 0;
}

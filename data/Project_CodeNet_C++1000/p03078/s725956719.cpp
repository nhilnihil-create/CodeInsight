#include <bits/stdc++.h>
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define ALL(x) (x).begin(),(x).end() 
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define INF 1000000000
using namespace std;
typedef long long ll;

int main() {
    int x, y, z, k;
    cin >> x >> y >> z >> k;

    ll a[x], b[y], c[z];
    REP(i, x){
        cin >> a[i];
    }
    REP(i, y){
        cin >> b[i];
    }
    REP(i, z){
        cin >> c[i];
    }

    sort(a, a+x, greater<ll>());
    sort(b, b+y, greater<ll>());
    sort(c, c+z, greater<ll>());

    vector<ll> ab;
    REP(i, x){
        REP(j, y){
            ll res = a[i] + b[j];
            ab.push_back(res);
        }
    }

    sort(ab.rbegin(), ab.rend());

    vector<ll> abc;
    REP(i, min(x*y, 3001)){
        REP(j, z){
            ll res = ab[i] + c[j];
            abc.push_back(res);
        }
    }

    sort(abc.rbegin(), abc.rend());
    REP(i, k){
        cout << abc[i] << endl;
    }
}
#include <bits/stdc++.h>

#define REP(i, n) for(ll i = 0; i <= n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 1e9
#define ALL(v) v.begin(), v.end()

using namespace std;
typedef unsigned long long ll;

int main(){
    // read in integers
    ll n, y;
    cin >> n >> y;

    REP(i, n){
        REP(j, n){
            if (i+j > n) continue;
            if ((i*10000) + (j*5000) + ((n-i-j)*1000) == y){
                cout << i << ' ' << j << ' ' << n-i-j << endl;
                return 0;
            }
        }
    }
    cout << "-1 -1 -1" << endl;
    return 0;

}
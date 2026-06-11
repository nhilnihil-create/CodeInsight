#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 1e9
#define ALL(v) v.begin(), v.end()

using namespace std;
typedef unsigned long long ll;

int main(){
    ll n;
    cin >> n;
    vector<ll> x(n, 0);
    REP(i, n) cin >> x[i];

    vector<ll>cpy = x;
    sort(ALL(cpy));

    REP(i, n){
        if (x[i] < cpy[n/2]){
            cout << cpy[n/2] << endl;
        }
        else{
            cout << cpy[n/2-1] << endl;
        }
    }
}
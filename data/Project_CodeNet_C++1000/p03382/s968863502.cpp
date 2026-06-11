#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
const ull mod = 1e9 + 7;
#define REP(i,n) for(int i=0;i<(int)n;++i)

int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    REP(i, n){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll res1 = a[n-1];
    ll res2;
    ll min_dist = 1e10;
    REP(i, n-1){
        if(abs(a[i]-(res1+1)/2)<min_dist){
            min_dist = abs(a[i]-(res1+1)/2);
            res2 = a[i];
        }
    }
    cout << res1 << " " << res2 << endl;
    return 0;
}
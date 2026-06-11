#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define REP(i,n) for (ll i = 0; i < (n); ++i)
#define RREP(i, n) for (ll i = (n) - 1; i >= 0; --i)
#define ALL(v) (v).begin(), (v).end()


int main(){
    ll n, m, d;
    cin >> n >> m >> d;
    if(d == 0){
        printf("%.10f\n", float(m - 1) / n);
    }else{
        printf("%.10f\n", float(2 * (m - 1) * (n - d)) / n / n);
    }
    return 0;
}

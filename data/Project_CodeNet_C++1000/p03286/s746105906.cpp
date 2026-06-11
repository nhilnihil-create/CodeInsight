#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
template<typename T> auto compare = [](T x, T y) -> bool{return (x < y);};
const int MOD = 1000000007;

ll N, a[100010];

signed main(){
    cin >> N;
    ll n = 1, sum = 0, i = 0;
    while(N != 0){
        n = abs(N) % 2;
        if(N < 0) n = (2 - n) % 2;
        a[i] = n; i++;
        N = (N - n) / (-2);
    }
    if(i == 0) i++;
    for(int j = i - 1; j >= 0; j--){
        cout << a[j];
    }
    cout << endl;
    return 0;
}
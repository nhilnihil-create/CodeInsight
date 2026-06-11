#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
#define ld long double
#define ll long long

const int MOD =  1000000007;
const int IINF = INT_MAX;
const ll INF = 1LL << 60;


int main() {
    int n, k; cin >> n >> k;

    if(n % k == 0) cout << 0 << endl;
    else cout << 1 << endl;
    return 0;
}

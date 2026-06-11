#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
#define ld long double
#define ll long long
#define mod 1000000007
#define IINF INT_MAX
#define INF 1LL << 30


int main() {
    int n, m; cin >> n >> m;
    V<int> l(m), r(m);
    for(int i = 0; i < m; i++) cin >> l[i] >> r[i];

    sort(ALL(l));
    sort(ALL(r));

    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(l[m - 1] <= i && i <= r[0]){
            ans++;
        }
    }
    cout << ans << endl;


    return 0;
}

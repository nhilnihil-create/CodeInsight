#include <bits/stdc++.h>

#define FOR(i, l, r) for(ll i = l; i < r; i++)
#define rep(i, N) FOR(i, 0, N)

#define MOD 1000000007
#define INF 1000000000

using ll = long long int;
using namespace std;

typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
    ll a,b; cin >> a>>b;
    ll tmp = a;
    int ans = 0;
    while(tmp <= b){
        ans++;
        tmp *= 2;
    }

    cout << ans << "\n";
    return 0;
}

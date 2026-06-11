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
    ll K, A, B; cin >> K >> A >> B;
    ll ans = 1;
    if(A+2 >= B || K < A+1) ans += K;
    else{
      ans = A + (((K-A+1)/2)*(B-A)) + (K-A+1)%2;
    }

    cout << ans << "\n";
    return 0;
}

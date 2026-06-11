#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <functional>
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define ALL(a) (a).begin(), (a).end()
 
int N, L[100001], R[100001];
 
int main() {
    cin >> N;
    REP(i, N) cin >> L[i] >> R[i];
    
    N++;
    sort(L, L + N, greater<int>());
    sort(R, R + N);
 
    ll ans = 0;
    for (int i = 0; i < N && L[i] > R[i]; i++) {
        ans += 2LL * (L[i] - R[i]);
    }
    cout << ans << endl;
    return 0;
}
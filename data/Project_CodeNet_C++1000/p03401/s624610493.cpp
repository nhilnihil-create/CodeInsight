#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<unordered_map>
#include<set>
#include<cstring>
#include<iomanip> //cout << fixed << setprecision(15) << x << endl;

using namespace std;
typedef long long ll;
const ll INF = 1e9 + 6;
const ll MOD = 1e9 + 7;
const ll LLINF = 1LL<<60;
#define P pair<int, int>
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */

int main() {
    int N; cin >> N;
    int A[N + 2]; rep(i, N) cin >> A[i + 1];
    A[0] = 0;
    A[N + 1] = 0;
    int sum = 0;
    rep(i, N + 1) sum += abs(A[i + 1] - A[i]);
    rep(i, N) {
        //A[i + 1]抜き
        int ans = sum - abs(A[i + 1] - A[i]) - abs(A[i + 1] - A[i + 2]) + abs(A[i + 2] - A[i]);
        cout << ans << endl;
    }
}

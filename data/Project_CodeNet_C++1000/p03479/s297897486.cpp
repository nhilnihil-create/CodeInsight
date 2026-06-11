#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> pii;
#define rep(i, start, n) for (int i = (int)(start); i < (int)(n); ++i)
#define all(a) a.begin(), a.end()
#define mp(a, b) make_pair(a, b)

const int MOD = 1e9+7;
const int INF = 1001001001;

int main(){
    ll N,M;
    cin >> N >> M;
    int ans = 0;
    while (N <= M){
        N *= 2;
        ans++;
    }
    cout << ans << endl;
}
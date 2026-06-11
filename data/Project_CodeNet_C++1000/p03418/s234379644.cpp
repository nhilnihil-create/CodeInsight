#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const ll INF = 1LL<<60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

typedef pair<int, int> P;

int main(){
    int N, K; cin >> N >> K;

    ll ans = 0;
    for (int b = 1; b <= N; b++){
        int div = N/b;
        int mod = N%b;
        ans += max(b-K,0)*div + max(mod-K+1, 0);
        if (K == 0) ans--;
    }

    cout << ans << endl;
}
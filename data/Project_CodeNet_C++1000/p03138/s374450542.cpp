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
#define Pint pair<int, int>
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */
int cnt[35]; //各桁に出現する1の数
vector<bool> K_b;
void toBinary(ll x) {
    while(x > 0) {
        if(x % 2) K_b.pb(1);
        else K_b.pb(0);
        x /= 2;
    }
    reverse(all(K_b));
}
int main() {
    ll N, K; cin >> N >> K;
    ll A[N]; rep(i, N) cin >> A[i];
    rep(i, N) {
        int j = 0;
        ll tmp = A[i];
        while(tmp > 0) {
            if(tmp % 2 == 1) cnt[j]++;
            ++j;
            tmp /= 2;
        }
    }
    ll ans = 0;
    toBinary(K);
    ll pow2 = pow(2, K_b.size() - 1);
    bool smaller = false;
    for(int i = 0; i < K_b.size(); ++i) {
        if(!smaller) {
            if(K_b[i]) {
                if((N - cnt[K_b.size() - 1 - i] > N / 2)) {
                    ans += pow2;
                }else {
                    smaller = true;
                }
            }
        }else {
            if((N - cnt[K_b.size() - 1 - i] > N / 2)) {
                ans += pow2;
            }
        }
        pow2 /= 2;
    }

    ll res = 0;
    rep(i, N) {
        res += ans ^ A[i];
    }
    cout << res << endl;
}

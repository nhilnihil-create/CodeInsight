#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp setprecision
#define pb(x) push_back(x)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ld, ld> pdd;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = 1e8;
const ll INF = 1e16;
const string alpha = "abcdefghijklmnopqrstuvwxyz";

int main(){
    int N, K;
    cin >> N >> K;
    int A[N];
    ll B[N];
    rep(i, N) cin >> A[i] >> B[i];
    ll ans = 0;
    rep(i, N){
        if((K|A[i]) == K) ans += B[i];
    }
    rep(i, 30){
        //i桁目が1でそこを0にする場合の総和
        if(K&(1<<i)){
            ll tmp = 0;
            rep(j, N){
                if(((K>>i)|(A[j]>>i)) == K>>i && !(A[j]&(1<<i))){
                    tmp += B[j];
                }
            }
            ans = max(ans, tmp);
        }
    }
    cout << ans << endl;
}
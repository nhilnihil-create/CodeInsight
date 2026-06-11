#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define repn(i, n) for(int (i) = 1; (i) <= (n); (i)++)
#define repr(i, n) for(int (i) = (n-1); (i) >= 0; (i)--)
#define all(x) (x).begin(), (x).end()
#define lint long long
#define ulint unsigned long long
#define fi first
#define se second
#define setpre(x) cout << fixed << setprecision(x)
#define ii(x) int x; cin >> (x)
#define ii2(x, y) int x, y; cin >> (x) >> (y)
#define ii3(x, y, z) int x, y, z; cin >> (x) >> (y) >> (z)
#define out(x) cout << (x) << endl
#define outs(x) cout << (x) << " "
#define yn(x) cout << ((x)?("Yes"):("No")) << endl
#define YN(x) cout << ((x)?("YES"):("NO")) << endl
#define bit_c(x) __builtin_popcountll(x)

inline void logger(){ cout << endl; }
template<typename A, typename... B>
void logger(const A& a, const B&... b){
    cout << a << " , ";
    logger(b...);
}

typedef pair<lint, lint> P;
const lint MOD = 1000000007;
const lint MOD9 = 998244353;
const lint INF = MOD * MOD;
const int MAX = 1000*1001/2+1;

/* ...o(^-^)o... */
bool ok[MAX], ng[MAX];

int main(){
    lint n, k; cin >> n >> k;
    vector<lint> a(n);
    rep(i, n) cin >> a[i];
    rep(i, n-1) a[i+1] += a[i];

    vector<lint> vec;
    rep(i, n) vec.push_back(a[i]);
    rep(i, n - 1){
        for(int j = i + 1; j < n; j++) vec.push_back(a[j] - a[i]);
    }

    lint ans = 0;
    for(int i = 40; i >= 0; i--){
        lint m = (1LL << i); lint cnt = 0;
        rep(j, vec.size()){
            ok[j] = false;
            if(!ng[j] && ((vec[j] & m) > 0)){
                ok[j] = true; cnt++;
            }
        }

        if(cnt >= k){
            ans += m;
            rep(j, vec.size()){
                if(!ok[j]) ng[j] = true;
            }
        }
    }

    out(ans);
}

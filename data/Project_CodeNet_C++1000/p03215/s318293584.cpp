#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
struct edge{ll to,cost;};
const int inf = 1<<27;
const ll INF = 1LL<<60;
const int COMBMAX = 1001001;
const ll MOD = 1000000007;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define eachdo(v, e) for(const auto& e : (v))
#define all(v) (v).begin(), (v).end()
#define lower_index(v, e) (ll)distance((v).begin(), lower_bound((v).begin(), (v).end(), e))
#define upper_index(v, e) (ll)distance((v).begin(), upper_bound((v).begin(), (v).end(), e))
ll mpow(ll a, ll n, ll mod = MOD){ll res = 1; while(n > 0){if(n & 1)res = res * a % mod; a = a * a % mod; n >>= 1;} return res;}
void YesNo(bool j){cout << (j ? "Yes" : "No") << endl; return;}
void yesno(bool j){cout << (j ? "yes" : "no") << endl; return;}
template<class Head> void pt(Head&& head){cout << head << endl; return;}
template<class Head, class... Tail> void pt(Head&& head, Tail&&... tail){cout << head << " "; pt(forward<Tail>(tail)...);}
template<class T> void debug(T v){rep(i, v.size()) cout << v[i] << " " ; cout << endl;}
template<class T> void debug2(T v){rep(i, v.size()){rep(j, v[i].size()) cout << v[i][j] << " " ; cout << endl;}}
template<class T1, class T2> ll bcount(T1 v, T2 a){return upper_index(v, a) - lower_index(v, a);} 
template<class T1, class T2> inline bool chmin(T1 &a, T2 b){if(a > b){a = b; return true;} return false;}
template<class T1, class T2> inline bool chmax(T1 &a, T2 b){if(a < b){a = b; return true;} return false;}


int main(){
    ll N, K; cin >> N >> K;
    vector<ll> a(N + 1);
    rep(i, N) cin >> a[i + 1];
    rep(i, N) a[i + 1] += a[i];
    vector<ll> s;
    rep(i, N + 1) rep(j, i) s.emplace_back(a[i] - a[j]);
    N = (N * (N + 1)) / 2;
    ll ans = 0;
    for(int i = 60; 0 <= i; --i){
        vector<bool> store(N, false);
        ll cnt = 0;
        rep(j, N){
            if (s[j] >> i & 1LL){
                cnt++;
                store[j] = true;
            }
        }
        if (K <= cnt){
            ans += (1LL << i);
            rep(j, N) if(!store[j]) s[j] = 0;
        }
    }
    pt(ans);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) REP(i,0,n)
#define REP(i,s,e) for(int i=(s); i<(int)(e); i++)
#define repr(i, n) REPR(i, n, 0)
#define REPR(i, s, e) for(int i=(int)(s-1); i>=(int)(e); i--)
#define pb push_back
#define all(r) r.begin(),r.end()
#define rall(r) r.rbegin(),r.rend()
#define fi first
#define se second

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const double EPS = 1e-8;

template<typename T> T chmax(T& a, const T& b){return a = (a > b ? a : b);}
template<typename T> T chmin(T& a, const T& b){return a = (a < b ? a : b);}

int main(){
    int n;
    cin >> n;
    vl a(n);
    rep(i, n) cin >> a[i];
    multiset<ll> st;
    rep(i, n) st.insert(-a[i]);
    int ans = 0;
    while(!st.empty()) {
        auto it = st.begin();
        ll x = -(*it);
        st.erase(it);
        repr(i, 32) {
            ll sum = 1LL << i;
            ll rest = sum - x;
            if(st.count(-rest)) {
                auto it2 = st.lower_bound(-rest);
                st.erase(it2);
                ++ans;
                break;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
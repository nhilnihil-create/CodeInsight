#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, a, b) for (int i = (a); i < (b); ++i)
#define PI acos(-1)
#define pcnt __builtin_popcountll
#define rng(a) a.begin(), a.end()
#define rrng(a) a.rbegin(), a.rend()
#define sz(x) (int)(x).size()
#define v(T) vector<T>
#define vv(T) v(v(T))
#define fi first
#define se second

using namespace std;
using ll = long long;
using P = pair<int, int>;
using LP = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

template<typename T>inline istream& operator>>(istream&i,v(T)&v)
{rep(j,sz(v))i>>v[j];return i;}
template<typename T1,typename T2>inline istream& operator>>(istream&i,pair<T1,T2>&v)
{return i>>v.fi>>v.se;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) {if (a > b) { a = b; return true; } return false; }

ll INF = 1001001001;
ll LINF = 1001001001001001001ll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n, m;
    cin>>n>>m;
    vl as(m);
    cin>>as;
    sort(rrng(as));
    rep(i, m) as[i]--;
    vl nums {2, 5, 5, 4, 5, 6, 3, 7, 6};

    vl dp(n + 1, -LINF);
    dp[0] = 0;
    rrep(i, 1, n + 1) rep(j, m) {
        if (i - nums[as[j]] >= 0) chmax(dp[i], dp[i - nums[as[j]]] + 1);
    }
    ll cur = n;
    string ans = "";
    while (cur > 0) {
        rep(j, m) {
            if (cur - nums[as[j]] >= 0 && dp[cur - nums[as[j]]] + 1 == dp[cur]) {
                ans.push_back(as[j] + 1 + '0');
                cur -= nums[as[j]];
                break;
            }
        }
    }
    cout<<ans<<endl;
}
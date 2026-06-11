#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i) 
#define PI acos(-1)
#define pcnt __builtin_popcountll
#define rng(a) a.begin(), a.end()
#define sz(x) (int)(x).size()
#define v(T) vector<T>
#define vv(T) v(v(T))
#define fi first
#define se second

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;

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

    ll n;
    cin>>n;
    vector<string> ss(n);
    cin>>ss;

    ll ans = 0;
    ll acnt = 0;
    ll bcnt = 0;
    ll abcnt = 0;
    rep(i, n) {
        int m = sz(ss[i]);
        rep(j, m - 1) {
            if (ss[i][j] == 'A' && ss[i][j + 1] == 'B') ans++;
        }
        if (ss[i][0] == 'B' && ss[i].back() == 'A') abcnt++;
        else if (ss[i][0] == 'B') bcnt++;
        else if (ss[i].back() == 'A') acnt++;
    }
    ans += max(abcnt - 1, 0ll);
    abcnt = abcnt > 0;
    if (abcnt <= min(acnt, bcnt)) {
        ans += abcnt * 2;
        acnt -= abcnt;
        bcnt -= abcnt;
        ans += min(acnt, bcnt);
    }
    else {
        if (acnt == 0) ans += min(abcnt, bcnt);
        else ans += min(abcnt, acnt);
    }
    cout<<ans<<endl;
}
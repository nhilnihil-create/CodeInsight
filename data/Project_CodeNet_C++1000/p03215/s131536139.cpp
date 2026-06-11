#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i) 
#define PI acos(-1)
#define pcnt __builtin_popcountll
#define rng(a) a.begin(), a.end()
#define sz(x) (int)(x).size()
#define v(T) vector<T>
#define vv(T) v(v(T))

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

    ll n, k;
    cin>>n>>k;
    vl as(n);
    cin>>as;
    vl ss(n + 1);
    rep(i, n) {
        ss[i + 1] = ss[i] + as[i];
    }
    vl bs;
    rep(l, n) for (int r = l + 1; r <= n; ++r) {
        ll num = ss[r] - ss[l];
        bs.push_back(num);
    }

    ll ans = 0;
    for (int i = 40; i >= 0; --i) {
        vl cs;
        ll cnt = 0;
        for (auto num : bs) {
            if (num>>i&1) {
                cnt++;
                cs.push_back(num);
            }
        }
        if (cnt >= k) {
            ans += (1ll<<i);
            swap(bs, cs);
        }
    }
    cout<<ans<<endl;
}
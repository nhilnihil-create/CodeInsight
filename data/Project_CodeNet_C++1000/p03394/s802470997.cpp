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
using ld = long double;
using P = pair<int, int>;
using LP = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using tl = tuple<ll, ll, ll>;

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

    ll n; cin>>n;
    if (n == 3) {
        cout<<2<<" "<<5<<" "<<63<<endl;
        return 0;
    }
    if (n == 4) {
        cout<<2<<" "<<5<<" "<<20<<" "<<63<<endl;
        return 0;
    }
    if (n == 5) {
        cout<<2<<" "<<5<<" "<<20<<" "<<30<<" "<<63<<endl;
        return 0;
    }

    ll cnt = 0;
    ll k = 0;
    ll s = 0;
    vl ans;
    ll c0 = 0, c4 = 0;
    rep(i, n) {
        ans.push_back(i * 6 + 2);
        s += i * 6 + 2;
        cnt++;
        if (cnt == n) break;
        ans.push_back(i * 6 + 3);
        s += i * 6 + 3;
        cnt++;
        if (cnt == n) break;
        ans.push_back(i * 6 + 4);
        s += i * 6 + 4;
        c4 = i * 6 + 4;
        cnt++;
        if (cnt == n) break;
        ans.push_back(i * 6 + 6);
        s += i * 6 + 6;
        c0 = i * 6 + 6;
        cnt++;
        if (cnt == n) break;
    }
    if (s % 6 == 2) {
        rep(i, n) if (ans[i] != 8) cout<<ans[i]<<endl;
        cout<<c0 + 6<<endl;
        return 0;
    }
    if (s % 6 == 3) {
        rep(i, n) if (ans[i] != 9) cout<<ans[i]<<endl;
        cout<<c0 + 6<<endl;
        return 0;
    }
    if (s % 6 == 5) {
        rep(i, n) if (ans[i] != 9) cout<<ans[i]<<endl;
        cout<<c4 + 6<<endl;
        return 0;
    }
    rep(i, n) cout<<ans[i]<<endl;
}
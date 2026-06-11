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

    int n, c;
    cin>>n>>c;
    vvi tsc(n, vi(3));
    rep(i, n) cin>>tsc[i][0]>>tsc[i][1]>>tsc[i][2];

    sort(rng(tsc));
    priority_queue<P, vector<P>, greater<P>> cuse;
    int ans = 0;
    rep(i, n) {
        while (!cuse.empty()) {
            if (cuse.top().fi < tsc[i][0]) cuse.pop();
            else {
                queue<P> temp;
                while (!cuse.empty() && cuse.top().fi == tsc[i][0]) {
                    if (cuse.top().se == tsc[i][2]) {
                        cuse.pop();
                        break;
                    }
                    temp.push(cuse.top()); cuse.pop();
                }
                while (!temp.empty()) {
                    cuse.push(temp.front()); temp.pop();
                }
                break;
            }
        }
        cuse.push(P(tsc[i][1], tsc[i][2]));
        chmax(ans, sz(cuse));
    }
    cout<<ans<<endl;
}
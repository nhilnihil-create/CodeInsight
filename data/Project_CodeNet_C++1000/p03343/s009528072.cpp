#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
using ld = long double;
template <typename T>
using V = vector<T>;
template <typename T>
using VV = vector<vector<T>>;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define siz(v) (ll)(v).size()
#define rep(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define repr(i, a, n) for (ll i = n - 1; (ll)a <= i; i--)
#define lb lower_bound
#define ub upper_bound
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
const ll mod = 1000000007;
const ll INF = 1000000099;
const ll LINF = (ll)(1e18 + 99);
vector<ll> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
template <typename T, typename U>
void chmin(T &t, const U &u)
{
    if (t > u)
        t = u;
}
template <typename T, typename U>
void chmax(T &t, const U &u)
{
    if (t < u)
        t = u;
}
template <typename T>
T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template <typename T>
T mpow(T a, T n)
{
    T res = 1;
    for (; n; n >>= 1)
    {
        if (n & 1)
            res = res * a;
        a = a * a;
    }
    return res;
}


signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll n, k, q,ans=LINF;
    cin >> n >> k >> q;
    vector<ll> v(n), ord;
    rep(i, 0, n) cin >> v[i];

    ord = v;
    sort(all(ord));

    rep(i, 0, n)
    {
        ll st = ord[i],r=-1;
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        vector<ll> kho;
        rep(l,0,n){
            while(r<n && v[r+1]>=st){
                r++;
                pq.push(v[r]);
                if(r-l+1>=k){
                    kho.pb(pq.top());
                    pq.pop();
                }
            }
            l=r+1;
            r++;
            while(!pq.empty())pq.pop();
        }
        if(siz(kho)<q)continue;
        else{
            sort(all(kho));
            chmin(ans,kho[q-1]-st);
        }
        //cout<<ans<<endl;
    }
    cout<<ans<<endl;
}
//( ・ __ ・ ) KEEP BEING ORGANIZED
//CHECK overflow,vector_size,what to output?
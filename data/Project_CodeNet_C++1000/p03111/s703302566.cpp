#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<n;++i)
#define exrep(i, a, b) for(ll i = a; i < b; i++)
#define out(x) cout << x << endl
#define EPS (1e-7)
#define gearup ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long double ld;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<pair<int,int> > vpii;
typedef vector<vector<int> > vvi;
typedef vector<vector<char> > vvc;
typedef vector<vector<bool> > vvb;
typedef vector<vector<double> > vvd;
typedef vector<vector<string> > vvs;
typedef vector<ll> vl;
typedef vector<vector<ll> > vvl;
typedef vector<vector<vector<ll> > > vvvl;
ll MOD = 1000000007;
const long long L_INF = 1LL << 60;
const int INF = 2147483647; // 2^31-1
const double PI = acos(-1);
//cout<<fixed<<setprecision(10);

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template<class T> void debug(T v){rep(i,v.size()) cout<<v[i]<<" ";cout<<endl;}
const ll dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

signed main()
{   
    gearup;
    ll n;
    vl a(3);
    cin >> n >> a[0] >> a[1]>> a[2];
    vl l(n);
    rep(i,n)cin>>l[i];
    ll res = L_INF;
    for(int a1=1;a1<(1<<n);a1++){
        for(int a2=1;a2<(1<<n);a2++){
            if(a1 & a2) continue;
            for(int a3=1;a3<(1<<n);a3++){
                if(a1 & a3)continue;
                if(a2 & a3)continue;
                vl sum(3,0),cnt(3,0);
                rep(j,n){
                    if(a1 & (1<<j)){
                        sum[0]+=l[j];
                        cnt[0]++;
                    }
                    if(a2 & (1<<j)){
                        sum[1]+=l[j];
                        cnt[1]++;
                    }
                    if(a3 & (1<<j)){
                        sum[2]+=l[j];
                        cnt[2]++;
                    }
                }
                ll ans = 0;
                rep(j,3){
                    ans += abs(a[j] - sum[j]);
                    ans += 10 * (cnt[j]-1);
                }
                res = min(ans,res);
            }
        }
    }
    out(res);
}

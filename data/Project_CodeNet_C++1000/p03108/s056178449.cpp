#include "bits/stdc++.h"
using namespace std;
#define pb          push_back
#define mp          make_pair
#define ll          long long
#define pii         pair<ll, ll>
#define vi          vector<ll>
#define vii         vector<pii>
#define mi          map<ll, ll>
#define mii         map<pii, ll>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define rev(i,a,b)  for(int i=a;i>=b;i--)
#define lb          lower_bound
#define ub          upper_bound

#define bg(i)       i.begin()
#define fset(it,s)   for(auto it = s.begin(); it != s.end(); it++)
 
#define track(x)                 cerr<<#x<<": "<<x<<endl
#define track2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define track3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define track4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
 
#define ed(i)       i.end()
#define mem(a)	    memset(a, 0, sizeof(a))

#define MOD         1000000007
ll mult(ll a,ll b, ll p=MOD){return ((a%p)*(b%p))%p;}
ll add(ll a, ll b, ll p=MOD){return (a + b + p)%p;}
ll fpow(ll n, ll k, ll p = MOD) {ll r = 1; for (; k; k >>= 1LL) {if (k & 1LL) r = mult(r,n,p); n = mult(n,n,p);} return r;}
ll inv(ll a, ll p = MOD) {return fpow(a, p - 2, p);}
void self_max(int &a, int b) {a = max(a, b); }
void self_min(int &a, int b) {a = min(a, b); }
void self_add(int &a, int b, int p = MOD) { a += b; if(a >= p) a -= p;}
void self_sub(int &a, int b, int p = MOD) { a -= b; if(a < 0) a += p;}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
const int INF = 1e9 + 5;
#define N	    	400001
ll p[N];
ll cnt[N];
ll parent(ll par) {
    if(par == p[par])
        return par;
    return  p[par] = parent(p[par]);
}
void solve(){
    ll n, m;
    cin>>n>>m;
    rep(i, 1, n+1) {
        p[i] = i;
        cnt[i] = 1;
    }
    vector<pair<ll, ll>> edge;
    rep(i, 0, m) {
        ll a, b;
        cin>>a>>b;
        edge.pb(mp(a, b));
    }
    vector<ll> ans;
    ans.pb(n*(n-1) / 2);
    rev(i, m-1, 1) {
        ll p1,p2;
        p1 = parent(edge[i].x);
        p2 = parent(edge[i].y);
        if(p1 != p2) {
            ans.pb(ans.back() - cnt[p1] * cnt[p2]);
            if(cnt[p1] > cnt[p2]) {
                p[p2] = p[p1];
                cnt[p1] += cnt[p2];
            }
            else {
                p[p1] = p[p2];
                cnt[p2] += cnt[p1];
            }
        }
        else {
            ans.pb(ans.back());
        }
    }
    reverse(all(ans));
    for(ll i : ans)
        cout<<i<<endl;

}
int main() {
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(20);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
//	cin>>t;
	while(t--){
		solve();
	}
}



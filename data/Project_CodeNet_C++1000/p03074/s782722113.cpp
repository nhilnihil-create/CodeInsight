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

void solve(){
    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<pair<char, int>> cmp;
    cmp.pb(mp(s.front(), 1));
    rep(i,1,sz(s)) {
        pair<char, int> &tmp = cmp.back();
        if(s[i] == tmp.x)
            tmp.y++;
        else
            cmp.pb(mp(s[i],1));
    }
    vi zindex;
    rep(i,0,sz(cmp)) {
        if(cmp[i].x == '0')
            zindex.pb(i);
    }
    if(sz(zindex) == 0) {
        cout<<n<<endl;
        return;
    }

    int sum = 0;
    int ans = 0;
    if(cmp[0].x == '1')
        sum += cmp[0].y;
    rep(i,0,sz(zindex)) {
        int ind = zindex[i];
        int cnt = 0;
        if(ind+1 < sz(cmp))
            cnt = cmp[ind+1].y;
        sum += cmp[ind].y + cnt;
        if(i >= k) {
            ind = zindex[i-k];
            sum -= cmp[ind].y;
            if(ind-1 >= 0)
                sum -= cmp[ind-1].y;
        }
        ans = max(ans, sum);
    }
    sum = 0;
    if(cmp.back().x == '1')
        sum = cmp.back().y;

    rev(i, sz(zindex)-1, 0) {
        int ind = zindex[i];
        int cnt = 0;
        if(ind-1 >= 0) 
            cnt = cmp[ind-1].y;
        sum += cmp[ind].y + cnt;
        if(i < sz(zindex) - k) {
            ind = zindex[i+k];
            sum -= cmp[ind].y;
            if(ind + 1 < sz(cmp))
                sum -= cmp[ind+1].y;
        }
        ans = max(ans, sum);
    }
    cout<<ans<<endl;
    
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



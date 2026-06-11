#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define mfill(x,y) memset(x,y,sizeof(x))
#define all(v) v.begin(), v.end()
#define in(x,y,h,w) if(0<=x&&x<h&&0<=y&&y<w)
#define y0 y12345
#define y1 y54321

#ifdef LOCAL
#define debug(...) fprintf(stderr,__VA_ARGS__)
#else
#define debug(...) 42
#endif

using ul = unsigned long;
using ll = long long;
using P = pair<int, int>;
using vint = vector<int>;using vvint = vector<vector<int>>;
using vll = vector<ll>;using vvll = vector<vector<ll>>;
template<class T>bool chmax(T &a, const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b){if(a>b){a=b;return 1;}return 0;}
template <class T>void initvv(vector<vector<T> > &v, int a, int b, const T &t = T()){
    v.assign(a, vector<T>(b, t));
}
template <class T>T gcd(T &a, T &b){if(a<b){swap(a,b);} T r = a%b; while(r!=0){a=b;b=r;r=a%b;} return b;}

vint dx = {-1, 0, 1, 0}, dy = {0, -1, 0, 1};
vint dx8 = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8 = {-1, 0, 1, 1, 1, 0, -1, -1};

ll ab(ll a){return a*(a>0?1:(-1));}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    debug("debug test\n");
    int a, b, q;cin>>a>>b>>q;
    vll s(a+2), t(b+2), x(q);
    s[0] = -100000000000;rep(i, a){cin>>s[i+1];}
    s[a+1] = 100000000000;
    t[0] = -100000000000;rep(i, b){cin>>t[i+1];}
    t[b+1] = 100000000000;
    rep(i, q)cin>>x[i];
    sort(all(s));
    sort(all(t));
    rep(i, a+2){
        debug("%ld ", s[i]);
    }
    debug("\n");
    rep(i, b+2){
        debug("%ld ", t[i]);
    }
    debug("\n");
    rep(i, q){
        auto si = lower_bound(all(s), x[i]);
        auto ti = lower_bound(all(t), x[i]);
        ll smi, sma, tmi, tma;
        debug("si %ld\n", *si);
        ll sindex = (ll)distance(s.begin(), si);
        ll tindex = (ll)distance(t.begin(), ti);
        debug("sindex %d\n", sindex);
        debug("tindex %d\n", tindex);
        sma = s[sindex];smi = s[sindex-1];
        tma = t[tindex];tmi = t[tindex-1];

        /*if(x[i] <= s[0]){smi = s[0];sma = x[1];}
        else if(x[i] > s[a-1]){smi = s[a-2];sma = s[a-1];}
        else {sma = *si;si--;smi = *si;}
        
        if(x[i] <= t[0]){tmi = x[0];tma = x[1];}
        else if(x[i] > t[b-1]){tmi = t[b-2];tma = t[b-1];}
        else {tma = *ti;ti--;tmi = *ti;}*/
        ll ans = 100000000000;
        debug("%ld %ld %ld %ld\n", smi, sma, tmi, tma);
        chmin(ans, ab(x[i]-smi)+ab(smi-tmi));debug("%ld\n",ab(x[i]-smi)+ab(smi-tmi));
        chmin(ans, ab(x[i]-smi)+ab(smi-tma));debug("%ld\n",ab(x[i]-smi)+ab(smi-tma));
        chmin(ans, ab(x[i]-sma)+ab(sma-tmi));debug("%ld\n",ab(x[i]-sma)+ab(sma-tmi));
        chmin(ans, ab(x[i]-sma)+ab(sma-tma));debug("%ld\n",ab(x[i]-sma)+ab(sma-tma));
        chmin(ans, ab(x[i]-tmi)+ab(tmi-smi));debug("%ld\n",ab(x[i]-tmi)+ab(tmi-smi));
        chmin(ans, ab(x[i]-tmi)+ab(tmi-sma));debug("%ld\n",ab(x[i]-tmi)+ab(tmi-sma));
        chmin(ans, ab(x[i]-tma)+ab(tma-smi));debug("%ld\n",ab(x[i]-tma)+ab(tma-smi));
        chmin(ans, ab(x[i]-tma)+ab(tma-sma));debug("%ld\n",ab(x[i]-tma)+ab(tma-sma));
        cout << ans << endl;
    }

    return 0;
}

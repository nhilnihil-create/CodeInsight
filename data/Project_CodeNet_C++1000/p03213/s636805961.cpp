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

vll s = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    debug("debug test\n");
    ll n;cin>>n;
    vll ss(s.size(), 0);
    for(ll i = 2;i <= n;i++){
        ll t = i;
        rep(j, s.size()){
            while(t%s[j]==0){
                t /= s[j];
                ss[j]++;
            }
            if(t==1)break;
        }
    }
    ll ni = 0,yon = 0,juyon = 0,nijuyon = 0; 
    rep(i, s.size()){
        debug("s:%d ss:%d\n", s[i], ss[i]);
        if(ss[i]>=2)ni++;
        if(ss[i]>=4)yon++;
        if(ss[i]>=14)juyon++;
        if(ss[i]>=24)nijuyon++;
    }
    ll ans = 0;
    ans += (yon*(yon-1)/2)*(ni - 2);
    ans += juyon*(yon-1);
    ans += nijuyon*(ni-1);
    if(ss[0]>=74)ans++;
    cout << ans << endl;
    
    return 0;
}

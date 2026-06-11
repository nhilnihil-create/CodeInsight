#include <bits/stdc++.h>
#define itn int
#define REP(i, n) for (ll i = 0; i < n; i++)
#define IREP(i, n) for (ll i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (ll i = a; i < b + 1; i++)
#define all(v) v.begin(), v.end()
#define SENTINEL 2000000000
#define NIL -1
using namespace std;
typedef long long ll;

const ll MAX = 510000;
const ll INF = 1LL << 60;
const ll MOD = 1000000007;
template <class T>inline bool chmin(T &a, T b){if(a>b){a=b;return true;}return false;}
template <class T>inline bool chmax(T &a, T b){if(a<b){a=b;return true;}return false;}

int main()
{
    int a,b,q;
    cin >> a >> b >> q;
    vector<ll> s(a+2);
    REP(i,a){
        cin >> s[i+1];
    }
    s[0]=-30000000000;
    s.back()=30000000000;
    vector<ll> t(b+2);
    REP(i,b){
        cin >> t[i+1];
    }
    t[0]=-30000000000;
    t.back()=30000000000;
    REP(i,q){
        ll x;
        cin >> x;
        auto itr1=lower_bound(all(s),x);
        auto itr2=lower_bound(all(t),x);
        auto itr1_=itr1-1;
        auto itr2_=itr2-1;
        ll m=20000000001;
        chmin(m,max(*itr1-x,*itr2-x));
        chmin(m,max(x-*itr1_,x-*itr2_));
        chmin(m, min(*itr1 - x, x - *itr2_) * 2 + max(*itr1 - x, x - *itr2_));
        chmin(m, min(*itr2 - x, x - *itr1_) * 2 + max(*itr2 - x, x - *itr1_));
        cout << m << endl;
    }
}

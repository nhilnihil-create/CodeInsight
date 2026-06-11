/******************************************
*    AUTHOR:         julianferres         *
******************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(int i = (a); i < (int) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define show(v,n) cerr << #v << " = "; forn(i,n) cerr << v[i] << " "; cerr << endl;
#define esta(x,c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
const int inf = 1<<30; // const ll inf = 1LL<<62;
const int mod = 1e9+7; // 998244353
const int N  = 1e3+5;

struct S{
    ll w, s, v;
    void read(){
        cin >> w >> s >> v;
    }
    bool operator<(const S &other) const
    {
        return w + s < other.w + other.s;
    }
    void print(){
        cout << w << " " << s << " " << v << endl;
    }
};
vector<S> in(N);
const ll max_s = 20200;

int
main()
{
    FIN;
    int n; cin >> n;
    forn(i, n) in[i].read();

    sort(all(in));

    vi dp(max_s+1, 0);

    for(auto block: in){
        for (ll w = min(block.s, max_s - block.w); w >= 0; --w){
            dp[w + block.w] = max(dp[w + block.w], dp[w] + block.v);
        }
    }
    ll answer = 0;
    forn(i,max_s+1){
        answer = max(answer, dp[i]);
    }
    cout << answer << endl;

    return 0;
}

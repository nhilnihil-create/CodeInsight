#include <bits/stdc++.h>
#define itn int
#define REP(i, n) for (ll i = 0; i < n; i++)
#define IREP(i, n) for (ll i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
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
    int n,m;cin >> n >> m;
    vector<pair<int,int>> v(m);
    REP(i,m){
        int a,b;
        cin >> a >> b;
        v[i]=make_pair(b,a);
    }
    sort(all(v));
    int now=0;
    int ans=0;
    REP(i,m){
        if(v[i].second>now){
            ans++;
            now=v[i].first-1;
        }
    }
    cout << ans << endl;
}

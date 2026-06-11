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

vector<vector<int>> v(500,vector<int>(500,0));
int main()
{
    int n,m,q;
    cin >> n >> m >> q;
    REP(i,m){
        int l,r;cin >> l >> r;
        l--;r--;
        v[l][r]++;
    }
    REP(i,n){
        REP(j,n){
            if(j==0)continue;
            v[i][j]+=v[i][j-1];
        }
    }
    REP(i,q){
        int p,q;cin >> p >> q;
        p--;q--;
        int ans=0;
        FOR(j,p,q+1){
            ans+=v[j][q];
        }
        cout << ans << endl;
    }
}

#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
 
const ll INF = 1LL<<60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

typedef pair<int, int> P;
typedef priority_queue<int, vector<int>, greater<int>> PQ;
const int MOD = 1000000007;

const int maxv = 100005;

int main(){

    int N, M; cin >> N >> M;
    vector<vector<ll>> xyz(3, vector<ll>());
    rep(i,N){
        ll x, y, z; cin >> x >> y >> z;
        xyz[0].push_back(x);
        xyz[1].push_back(y);
        xyz[2].push_back(z);
    }
    
    ll ans = 0;
    rep(i, 1<<3){
        vector<ll> a;
        rep(j,N){
            ll tmp = 0;
            rep(k,3){
                if (i & (1<<k)) tmp += xyz[k][j];
                else tmp -= xyz[k][j];
            }
            a.push_back(tmp);
        }

        sort(a.begin(), a.end(), greater<ll>());

        ll total = 0;
        rep(i,M) total += a[i];

        ans = max(ans, total);
    }

    cout << ans << endl;
 }
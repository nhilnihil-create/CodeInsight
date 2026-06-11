#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
//using namespace boost::multiprecision;
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> P;
#define PI 3.141592653589793
#define MOD 1000000007
//#define MOD 998244353
#define ALL(obj) (obj).begin(),(obj).end()
const ll INF = 1LL << 60;
//四方向への移動ベクトル
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
bool pairCompare(const pair<double,ll>& firstElof, const pair<double,ll>& secondElof){
    return firstElof.first < secondElof.first;
}

struct edge{//グラフに使うヤツ
    ll from,to,cost;
};

typedef vector<vector<edge> > G;

ll gcd(ll a,ll b){
    if (a%b==0)return(b);
    else return(gcd(b,a%b));
}

int main() { 
    ll n,m,q;
    cin >> n >> m >> q;
    ll ex[n+1][n+1];
    memset(ex,0,sizeof(ex));
    for (ll i=0;i<m;i++){
        ll l,r;
        cin >> l >> r;
        for (ll j=r;j<=n;j++){
            ex[l][j]++;
        }
    }
    for (ll i=n;i>=1;i--){
        for (ll j=0;j<=n;j++){
            ex[i-1][j]+=ex[i][j];
        }
    }
    for (ll i=0;i<q;i++){
        ll l,r;
        cin >> l >> r;
        cout << ex[l][r] << endl;
    }
    return 0;
}


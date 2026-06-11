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
template<class T>inline bool chmax(T& a,T b){if (a<b){a=b;return 1;}return 0;}
template<class T>inline bool chmin(T& a,T b){if (a>b){a=b;return 1;}return 0;}
const ll INF = 1LL << 60;

//四方向への移動ベクトル
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

struct edge{//グラフに使うヤツ
    ll from,to,cost;
};

typedef vector<vector<edge> > G;
ll gcd(ll a,ll b){
    if (a%b==0)return(b);
    else return(gcd(b,a%b));
}

int main() {
    ll n;
    cin >> n;
    vector<P> ki[n];
    for (ll i=0;i<n-1;i++){
        ll a,b,c;
        cin >> a >> b >> c;
        a--;
        b--;
        ki[a].push_back(P(b,c));
        ki[b].push_back(P(a,c));
    }
    ll color[n];
    bool visited[n];
    fill(visited,visited+n,false);

    queue<P> que;
    que.push(P(0,0));
    while(!que.empty()){
        P p=que.front();
        que.pop();
        ll x=p.first;
        visited[x]=true;
        color[x]=p.second%2;
        for (ll i=0;i<ki[x].size();i++){
            if (visited[ki[x][i].first])continue;
            que.push(P(ki[x][i].first,p.second+ki[x][i].second));
        }
    }
    for (ll i=0;i<n;i++){
        cout << color[i] << endl;
    }
    return 0;
}

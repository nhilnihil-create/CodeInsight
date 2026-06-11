#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <math.h>
#include <string.h>
#include <iomanip>
#include <numeric>
#include <cstdlib>
#include <cstdint>
#include <cmath>

using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using vl = vector<ll>;
using vll = vector<vl>;
using vpll = vector<pll>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; i--)
#define Rep(i, n) for (long long i = 0; i< (long long)(n); i++)
#define RRep(i,n) for (long long i = ((long long)(n)-1); i>=0; i--)

struct Edge{
    int to;
    int weight;
    Edge(int t, int w) : to(t), weight(w){ }
};

using Graph = vector<vector<Edge>>;
using graph = vector<vector<int>>;

template <class T>
inline bool chmin(T &a, T b){
    if (a > b){
        a = b;
        return true;
    }
    return false;
}

template <class T>
inline bool chmax(T &a, T b){
    if (a < b){
        a = b;
        return true;
    }
    return false;
}

template <class T>
T gcd(T a, T b){
    if( b==0 ) return a;
    else return gcd(b, a%b);
}

template <class T>
T lcm(T a, T b){
    return (a*b)/gcd(a,b);
}

int INF = 1e9+7;

vector<int> dx = {-1,0,1,0};
vector<int> dy = {0,-1,0,1};

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    rep(i,n) cin >> a[i];
    rep(j,n) cin >> b[j];
    vector<ll> c;
    ll d = 0ll;
    ll ans = 0ll;
    Rep(i,n){
        if(a[i]-b[i]>=0) c.emplace_back(a[i]-b[i]);
        else{
            d += b[i]-a[i];
            ans++;
        }
    }
    sort(c.begin(),c.end());
    reverse(c.begin(),c.end());
    ll index = 0;
    while(d>0 && index < c.size()){
        d -= c[index];
        index++;
    }
    ans += index;
    if(d>0){
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
}
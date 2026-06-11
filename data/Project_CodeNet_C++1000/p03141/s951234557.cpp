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

using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using vl = vector<ll>;
using vll = vector<vl>;
using vpll = vector<pll>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; i--)
#define pb push_back
#define eb emplace_back

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

template<class T>
void dcomb(T n,T m, string s){
    if(n==0) cout << s << endl;
    else {
        for(T i=0; i<m; ++i){
            dcomb(n-1,m,s+to_string(i));
        }
    }
}

int main(){
    ll n;
    vl ab(n,0);
    ll ans = 0;
    cin >> n;
    rep(i,n){
        ll a,b;
        cin >> a >> b;
        ab[i] = a+b;
        ans -=b;
    }
    sort(ab.begin(),ab.end());
    reverse(ab.begin(),ab.end());
    rep(i,n){
        if(i%2==1) continue;
        ans += ab[i];
    }
    cout << ans << endl;
}
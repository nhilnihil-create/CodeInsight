//
//AtCoder Beginner Contest 079
//D
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <queue>
#include <map>
#include <set>
#include <tuple>
#include <functional>
#include <cassert>
#include <bitset>
#include <numeric>

using namespace std;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define ALL(x) (x).begin(),(x).end()
#define RALL(x) (x).rbegin(),(x).rend()
#define SIZE(x) (int)(x).size()
#define SIZEL(x) (ll)(x).size()
#define MSG(a) cout << #a << " " << a << endl;

using ll = long long;
using ld = long double;
using Graph = vector<vector<int>>;

const double PI = 3.14159265358979323846;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

ll gcd(ll x, ll y) { return (x % y)? gcd(y, x % y): y; }    //最大公約数
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }            //最小公倍数

int main()
{
    int H, W;
    cin >> H >> W;

    vector<vector<int>> c(10, vector<int>(10));
    REP(i,10)REP(j,10){
        cin >> c[i][j];
    }
    vector<int> aCnt(10,0);
    REP(h,H)REP(w,W){
        int a;
        cin >> a;
        if (a!=-1) aCnt[a]++;
    }
    
    REP(k,10)REP(i,10)REP(j,10){
        if (c[i][j]>c[i][k]+c[k][j]) c[i][j]=c[i][k]+c[k][j];
    }
    ll ans = 0;
    REP(i,10){
        ans += aCnt[i]*c[i][1];
    }
    cout << ans << endl;
    return 0;
}

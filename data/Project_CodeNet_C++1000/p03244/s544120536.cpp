//
//AtCoder Beginner Contest 111
//C
//https://atcoder.jp/contests/abc111/tasks/arc103_a
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
    int n;
    cin >> n;

    vector<pair<int,int>> vOddCnt(100010);
    vector<pair<int,int>> vEvenCnt(100010);

    REP(i,n){
        int v;
        cin >> v;
        if (i%2==0) {
            vOddCnt[v].first++;
            vOddCnt[v].second=v;
        }else {
            vEvenCnt[v].first++;
            vEvenCnt[v].second=v;
        }
    }
    sort(RALL(vOddCnt));
    sort(RALL(vEvenCnt));

    int ans=0;
    if (vOddCnt[0].second == vEvenCnt[0].second){
        int a1 = (n/2 - vOddCnt[0].first) + (n/2 - vEvenCnt[1].first);
        int a2 = (n/2 - vOddCnt[1].first) + (n/2 - vEvenCnt[0].first);
        ans = min(a1, a2);
    }else{
        ans += n/2 - vOddCnt[0].first;
        ans += n/2 - vEvenCnt[0].first;
    }
    cout << ans << endl;
    return 0;
}

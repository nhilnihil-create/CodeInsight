//
//AtCoder Beginner Contest 082
//C
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

    vector<int> a(n);
    REP(i, n) cin >> a[i];

    sort(ALL(a));

    int ans = 0;
    int bef = -1;
    int cnt = 1;
    REP(i, n){
        if (bef==a[i]) {
            cnt++;
        }else{
            if (bef!=-1){
                if(bef>cnt) ans+=cnt;
                if(bef<cnt) ans+=cnt-bef;
            }
            bef=a[i];
            cnt=1;
        }
    }
    if (bef!=-1){
        if(bef>cnt) ans+=cnt;
        if(bef<cnt) ans+=cnt-bef;
    }
    cout << ans << endl;
    return 0;
}

//
//AtCoder Beginner Contest 128
//C - Switches
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

const double PI = 3.14159265358979323846;

ll gcd(ll x, ll y) { return (x % y)? gcd(y, x % y): y; }    //最大公約数
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }            //最小公倍数

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> ss(m);
    REP(i, m) {
        int k;
        cin >> k;
        REP(j,k){
            int s;
            cin >> s;
            s--;
            ss[i].push_back(s);
        }
    }
    vector<int> p(m);
    REP(i,m) cin >> p[i];

    int ans=0;
    int maxPattern = pow(2,n);
    REP(i, maxPattern){
        bool allOn=true;
        REP(j, m){
            int onSwitchCnt=0;
            REP(k, ss[j].size()){
                onSwitchCnt += ((i >> ss[j][k]) & 1);
                //cout << i << " " << j << " " << k << ":" << ((i >> ss[j][k]) & 1) << endl;
            }
            if (p[j]!=onSwitchCnt%2){
                allOn = false;
                break;
            }
        }
        if (allOn) ans++;
    }
    cout << ans << endl;
    return 0;
}

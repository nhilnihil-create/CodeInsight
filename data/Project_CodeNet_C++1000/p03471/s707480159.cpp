//
//AtCoder Beginner Contest 085
//C - Otoshidama
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
    int n, y;
    cin >> n >> y;

    int b10=-1;
    int b05=-1;
    int b01=-1;
    FOR(i,0,n){
        FOR(j,0,n-i){
            if ((i*10000+j*5000+(n-i-j)*1000) == y){
                b10 = i;
                b05 = j;
                b01 = n-i-j;
                break;
            }
        }
    }
    cout << b10 << " " << b05 << " " << b01 << endl;
    return 0;
}

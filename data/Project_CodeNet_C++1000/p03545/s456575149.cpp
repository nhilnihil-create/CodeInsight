//
//AtCoder Beginner Contest 079
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

int calc(int f, int x, int y){
    if (f==0) return x+y;
    else return x-y;
}
int main()
{
    int abcd;
    cin >> abcd;
    int d = abcd%10; abcd/=10;
    int c = abcd%10; abcd/=10;
    int b = abcd%10; abcd/=10;
    int a = abcd%10;

    REP(i,2)REP(j,2)REP(k,2){
        if (calc(k,calc(j,calc(i,a,b),c),d)==7){
            cout << a << ((i==0) ? "+" : "-") ;
            cout << b << ((j==0) ? "+" : "-");
            cout << c << ((k==0) ? "+" : "-");
            cout << d << "=7" << endl;
            return 0;
        }
    }

    return 0;
}

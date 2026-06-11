#include<algorithm>
#include<bitset>
#include<cmath>
#include<complex>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<iterator>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>

using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define ALL(x) (x).begin(),(x).end()
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define D()
#define INF 1000000000000
#define MOD 10000007
#define MAXR 100000
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define INITA(a,i,j,v) for(ll k=i;k<=j;k++){a[k]=v;}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int res = 0;
    if (a >= b && a >= c) {
        int d = a - max(b, c);
        res += d;
        b += d;
        c += d;
        if ((a - min(b, c)) % 2 == 0) {
            res += (a - min(b, c)) / 2;
        } else {
            res += (a - min(b, c) + 1) / 2 + 1;
        }
    } else if (b >= a && b >= c) {
        int d = b - max(a, c);
        res += d;
        a += d;
        c += d;
        if ((b - min(a, c)) % 2 == 0) {
            res += (b - min(a, c)) / 2;
        } else {
            res += (b - min(a, c) + 1) / 2 + 1;
        }
    } else {
        int d = c - max(a, b);
        res += d;
        a += d;
        b += d;
        if ((c - min(a, b)) % 2 == 0) {
            res += (c - min(a, b)) / 2;
        } else {
            res += (a - min(a, b) + 1) / 2 + 1;
        }
    }
    cout << res << endl;
    return 0;
}
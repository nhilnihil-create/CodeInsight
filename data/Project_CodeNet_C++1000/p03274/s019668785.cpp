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
    ll n, k; cin >> n >> k;
    vector<ll> v(n, 0);
    REP(i, n) {
        cin >> v[i];
    }

    ll res = 10e10;
    FOR(i, 0, n-k) {
        ll left = v[i];
        ll right = v[i+k-1];

        if (left == right) {
            res = min(res, abs(left));
        } else if (left < 0 && right <= 0) {
            res = min(res, abs(left));
        } else if (left >= 0 && right > 0) {
            res = min(res, abs(right));
        } else if (abs(left) < abs(right)) {
            res = min(res, abs(left)*2 + abs(right));
        } else {
            res = min(res, abs(right)*2 + abs(left));
        }
    }
    cout << res << endl;
    // 5 3
    // -30 -10 10 20 50

    // 0がない場合: 左右合わせてkをつける
    // 0がある場合: 左右合わせてk-1をつける
    // コスト計算はそれぞれ端だけ考えれば良い
    // 0 -> -10 -> 20: 40
    return 0;
}
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
    ll n; cin >> n;
    string s; cin >> s;

    // 全て異なる文字の場合は、それぞれのオンオフ考慮して-1なので2*n-1
    // 重複文字がある場合は重複文字に関してはその重複数通り
    map<char, ll> m;
    REP(i, n) {
        if (m.find(s[i]) == m.end()) {
            m[s[i]] = 0;
        }
        m[s[i]]++;
    }
    ll res = 1;
    for (auto e:m) {
        // 同じ文字の中からの選び方は、どれかを選ぶかどれも選ばないか
        res *= (e.second + 1);
        res %= 1000000007;
    }
    // すべての文字を選ばないことはできないので-1
    res -= 1;

    cout << res << endl;
    return 0;
}
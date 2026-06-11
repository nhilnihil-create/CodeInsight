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
    set<ll> st;
    map<ll, ll> odd_m;
    map<ll, ll> even_m;

    // 奇数個目、偶数個目それぞれで各値をカウント (map)
    // 出現頻度最大とその次点を確認
    REP(i, n) {
        ll tmp;
        cin >> tmp;
        st.insert(tmp);

        if (i % 2 == 0) {
            even_m[tmp]++;
        } else {
            odd_m[tmp]++;
        }
    }

    using p = pair<ll, ll>;
    vector<p> odd_v;
    vector<p> even_v;

    for (auto e:odd_m) {
        odd_v.push_back(make_pair(e.second, e.first));
    }

    for (auto e:even_m) {
        even_v.push_back(make_pair(e.second, e.first));
    }

    sort(ALL(odd_v), greater<>());
    sort(ALL(even_v), greater<>());

    // (1) それぞれ2種類以上ある場合 -> 最上位が違う場合は単純にそれ以外をreplace。違う場合1:5-2:3, 1:7-2:1として、最上位頻度が多いほうを選択し、残りは2番目を使う
    // (2) 片方が1種類の場合 -> (1) と同様でいける？2番目がない場合は、片方が1であれば2、そうでなければ1とする
    // (3) どちらも1種類の場合 -> (1) と同様かつ、片方を先に決定するパターン

    ll odd_fix;
    ll even_fix;
    if ((odd_v[0].first > even_v[0].first) || ( (odd_v.size() > 1) && (even_v.size() > 1) && (odd_v[0].first == even_v[0].first) && (odd_v[1].first < even_v[1].first) )) {
        // 奇数のほうを固定
        odd_fix = odd_v[0].second;
        if (even_v[0].second == odd_fix) {
            if (even_v.size() > 1) {
                even_fix = even_v[1].second;
            } else {
                if (odd_fix == 1) {
                    even_fix = 2;
                } else {
                    even_fix = 1;
                }
            }
        } else {
            even_fix = even_v[0].second;
        }
    } else {
        // 偶数のほうを固定
        even_fix = even_v[0].second;
        if (odd_v[0].second == even_fix) {
            if (odd_v.size() > 1) {
                odd_fix = odd_v[1].second;
            } else {
                if (even_fix == 1) {
                    odd_fix = 2;
                } else {
                    odd_fix = 1;
                }
            }
        } else {
            odd_fix = odd_v[0].second;
        }
    }
    cout << n - odd_m[odd_fix] - even_m[even_fix] << endl;
    return 0;
}
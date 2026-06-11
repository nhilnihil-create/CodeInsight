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
    vector<string> v;
    ll res = 0;
    ll a_end_num = 0;
    ll b_start_a_end_num = 0;
    ll b_start_num = 0;
    REP(i, n) {
        string tmp; cin >> tmp;
        v.push_back(tmp);

        FOR(j, 0, tmp.size()-2) {
            if (tmp[j] == 'A' && tmp[j+1] == 'B') {
                res++;
            }
        }

        if ((tmp.substr(tmp.size()-1, 1) == "A") && (tmp.substr(0, 1) == "B")) {
            b_start_a_end_num++;
        } else if (tmp.substr(tmp.size()-1, 1) == "A") {
            a_end_num++;
        } else if (tmp.substr(0, 1) == "B") {
            b_start_num++;
        }
    }
    // sort(ALL(v));
    // Aおわり、Bはじまり、Aおわり、Bはじまり、を繰り返せるだけ繰り返してインクリメント。2で割ったのをresに追加
    // 最初はbaがあってもaから消化。つぎはbaがあるかぎりba。なくなったらa
    // REP(i, n) {
    //     cout << v[i] << endl;
    // }
    bool before_a = false;
    // cout << res << endl;
    // cout << a_end_num << " " << b_start_num << " " << a_end_b_start_num << endl;
    FOR(i, 0, 12345) {
        if (i == 0) {
            // 1つめの文字列だけ処理が特殊になるので分岐
            if (a_end_num > 0) {
                a_end_num--;
                before_a = true;
            } else if (b_start_a_end_num > 0) {
                b_start_a_end_num--;
                before_a = true;
            } else {
                // Aおわりがないと以降ABを作れないので抜ける
                break;
            }
        } else if (before_a) {
            // 直前がAで終わっている場合はBを付けに行く。なおかつ次につなげるためにA終わりのものから優先して取得
            if (b_start_a_end_num > 0) {
                res++;
                b_start_a_end_num--;
                before_a = true;
            } else if (b_start_num > 0) {
                res++;
                b_start_num--;
                before_a = false;
            } else {
                before_a = false;
            }
        } else if (a_end_num > 0) {
            // before_aでなくても、Aで終わることができるなら追加
            a_end_num--;
            before_a = true;
        } else {
            break;
        }
        // cout << a_end_num << " " << b_start_num << " " << a_end_b_start_num << endl;
    }
    // cout << a_end_num << " " << b_start_num << " " << a_end_b_start_num << endl;
    cout << res << endl;
    return 0;
}
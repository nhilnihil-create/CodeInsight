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
    int n, m; cin >> n >> m;
    vector<int> k; // 電球ごとに接続されているスイッチ数
    vector< bitset<10> > s; // 電球ごとに接続されているスイッチ
    vector<int> p; // 電球ごとに光る条件となる、接続数を2で割った余り

    REP(i, m) {
        int tmp_k;
        cin >> tmp_k;
        k.push_back(tmp_k);

        bitset<10> row_s;
        REP(j, tmp_k) {
            int tmp_s;
            cin >> tmp_s;
            row_s[tmp_s-1] = true;
        }
        s.push_back(row_s);
    }
    REP(i, m) {
        int tmp_p;
        cin >> tmp_p;
        p.push_back(tmp_p);
    }

    // 方針: スイッチの数はたかだか10個なので、全通り試して10!なので回りきる？
    ll res = 0;
    for (int bit=0; bit < (1 << n); bit++) {
        // 発火するbitを見る
        bitset<10> vb;
        for (int i=0; i < n; i++) {
            if (bit & (1 << i)) {
                vb[i] = 1;
            }
        }

        // 電球ごとに一致数を確認する
        int on_num = 0;
        for (int i=0; i < m; i++) {
            if ((s[i] & vb).count() % 2 == p[i]) {
                on_num++;
            }
        }

        // 全て光る組み合わせであればOK
        if (on_num == m) {
            res++;
        }
    }
    cout << res << endl;
    return 0;
}
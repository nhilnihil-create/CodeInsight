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
    string s, t; cin >> s >> t;
    vector<string> v;
    FOR(i, 0, s.size()-t.size()) {
        // s[i] からt文字分を見たとき、ハテナ以外は一致しているか確認
        string sub = s.substr(i, t.size());
        bool ok = true;
        REP(j, t.size()) {
            if (sub[j] != '?' && sub[j] != t[j]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            // 元の文字列のiからt.size()個をtに置き換えた文字列を作る
            string m;
            if (i > 0) {
                m = s.substr(0, i) + t + s.substr(i+t.size());
            } else {
                m = t + s.substr(i+t.size());
            }
            replace(m.begin(), m.end(), '?', 'a');
            v.push_back(m);
        }
    }
    if (v.size() > 0) {
        sort(ALL(v));
        cout << v[0] << endl;
    } else {
        cout << "UNRESTORABLE" << endl;
    }
    return 0;
}
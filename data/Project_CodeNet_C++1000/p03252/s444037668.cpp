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
    map<char, ll> sm;
    map<char, ll> tm;
    ll cur_s = 1;
    ll cur_t = 1;

    vector<int> sv;
    vector<int> tv;
    REP(i, s.size()) {
        char c = s[i];
        if (sm[c] == 0) {
            sm[c] = cur_s;
            cur_s++;
        }
        sv.push_back(sm[c]);
    }

    REP(i, t.size()) {
        char c = t[i];
        if (tm[c] == 0) {
            tm[c] = cur_t;
            cur_t++;
        }
        tv.push_back(tm[c]);
    }

    // REP(i, sv.size()) {
    //     cout << sv[i];
    // }
    // cout << endl;

    // REP(i, tv.size()) {
    //     cout << tv[i];
    // }

    if (sv == tv) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long lint;
typedef long long llint;
typedef pair<int, int> pint;
typedef pair<long long, long long> pllint;

// static const int MAX = 1e6;
// static const int NIL = -1;
// static const llint INF = 1<<21;
// static const llint MOD = 1e9 + 7;

bool compPair(const pint& arg1, const pint& arg2) { return arg1.first > arg2.first; }
template<class T> void chmax(T& a, T b) { if (a < b) { a = b; } }
template<class T> void chmin(T& a, T b) { if (a > b) { a = b; } }

int main(void) {
    int h, w, d;
    cin >> h >> w >> d;

    vector<pint> a(h*w+1);
    vector<int> s(h*w+1);
    int atmp = 0;
    for(int ih=0;ih<h;ih++) {
        for(int iw=0;iw<w;iw++) {
            cin >> atmp;
            a.at(atmp) = make_pair(ih+1, iw+1);
        }
    }

    int q;
    cin >> q;

    for(int id=d+1;id<=h*w;id++) {
        s.at(id) = s.at(id-d) + abs(a.at(id).first-a.at(id-d).first) + abs(a.at(id).second-a.at(id-d).second);
    }

    int l, r;
    for(int iq=0;iq<q;iq++) {
        cin >> l >> r;
        cout << s.at(r)-s.at(l) << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

typedef long lint;
typedef long long llint;
typedef pair<int, int> pint;
typedef pair<long long, long long> pllint;
typedef tuple<long long, long long, long long, long long> tllint;

// static const int MAX = 1e6;
// static const int NIL = -1;
// static const llint INF = 1<<21;
// static const llint MOD = 1e9 + 7;

bool compPair(const pint& arg1, const pint& arg2) { return arg1.first > arg2.first; }
bool compTuple(const tllint& arg1, const tllint& arg2) { return get<3>(arg1) > get<3>(arg2); }
template<class T> bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main(void) {
    llint n, m;
    cin >> n >> m;

    vector<tllint> xyzm(n);
    llint x, y ,z;
    for(int in=0;in<n;++in) {
        cin >> x >> y >> z;
        xyzm[in] = make_tuple(x, y, z, 0);
    }

    llint ans = -1e18, anstmp, anstmpx, anstmpy, anstmpz;
    llint sgnx, sgny, sgnz;
    llint xtmp, ytmp, ztmp;
    for(int in=0;in<8;++in) {
        if(in&1) sgnx = 1;
        else sgnx = -1;
        if((in>>1)&1) sgny = 1;
        else sgny = -1;
        if((in>>2)&1) sgnz = 1;
        else sgnz = -1;
        for(int in=0;in<n;++in) {
            xtmp = get<0>(xyzm[in]);
            ytmp = get<1>(xyzm[in]);
            ztmp = get<2>(xyzm[in]);
            xyzm[in] = make_tuple(xtmp, ytmp, ztmp, sgnx*xtmp+sgny*ytmp+sgnz*ztmp);
        }
        sort(xyzm.begin(), xyzm.end(), compTuple);
        anstmpx = 0; anstmpy = 0; anstmpz = 0;
        for(int im=0;im<m;++im) {
            anstmpx += get<0>(xyzm[im]);
            anstmpy += get<1>(xyzm[im]);
            anstmpz += get<2>(xyzm[im]);
        }
        anstmpx = abs(anstmpx);
        anstmpy = abs(anstmpy);
        anstmpz = abs(anstmpz);
        anstmp = anstmpx + anstmpy + anstmpz;
        chmax(ans, anstmp);
    }
    cout << ans << endl;
    return 0;
}

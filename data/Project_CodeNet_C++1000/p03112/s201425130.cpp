#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ALL(x) (x).begin(),(x).end()
const int IINF = 1e9;
const LL LINF = 1e18;
const LL MOD = 1e9+7;

int search(vector<LL> &v, LL x) {
    int left = 0;
    int right = v.size() - 1;
    if(v[right] < x) {
        return right;
    }
    if(x < v[left]) {
        return left;
    }
    for(;1 < right - left;) {
        int mid = (left + right)/2;
        if(v[mid] < x) {
            left = mid;
        }else{
            right = mid;
        }
    }
    return left;
}

int main() {
    int A, B, Q;
    cin >> A >> B >> Q;
    vector<LL> s(A);
    vector<LL> t(B);

    REP(i, A) {
        cin >> s[i];
    }
    REP(i, B) {
        cin >> t[i];
    }

    REP(q, Q) {
        LL x;
        cin >> x;

        int ls = search(s, x);
        int rs = min(A - 1, ls + 1);
        int lt = search(t, x);
        int rt = min(B - 1, lt + 1);
        vector<vector<LL>> v = {{s[ls], s[rs]}, {t[lt], t[rt]}};
        LL res = LINF;
        REP(i, 2) {
            REP(j, 2) {
                LL a = abs(v[0][i] - x) + abs(v[1][j] - v[0][i]);
                LL b = abs(v[1][i] - x) + abs(v[0][j] - v[1][i]);
                res = min({res, a, b});
            }
        }
        cout << res << endl;
    }
    return 0;
}

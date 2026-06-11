#include <bits/stdc++.h>
using namespace std;

typedef long lint;
typedef long long llint;
typedef pair<int, int> pint;
typedef pair<long long, long long> pllint;
typedef tuple<long long, long long, long long> tllint;

// static const int MAX = 1e6;
// static const int NIL = -1;
// static const llint INF = 1<<21;
// static const llint MOD = 1e9 + 7;

bool compPair(const pint& arg1, const pint& arg2) { return arg1.first > arg2.first; }
bool compTuple(const tllint& arg1, const tllint& arg2) { return get<2>(arg1) > get<2>(arg2); }
template<class T> void chmax(T& a, T b) { if (a < b) { a = b; } }
template<class T> void chmin(T& a, T b) { if (a > b) { a = b; } }

int main(void) {
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for(int in=0;in<n;++in) {
        cin >> v[in];
    }

    int m = min(n,k), ans = 0;
    for(int a=0;a<=m;++a) {
        for(int b=0;b<=m-a;++b) {
            vector<int> d;
            int anstmp = 0;
            
            for(int ia=0;ia<a;++ia) {
                d.push_back(v[ia]);
            }
            for(int ib=0;ib<b;++ib) {
                d.push_back(v[n-ib-1]);
            }

            sort(d.begin(), d.end());
            for(int ik=0;ik<k-a-b;++ik) {
                if(d.empty()) break;
                if(d[ik]>=0) break;
                d[ik] = 0;
            }

            for(auto id:d) anstmp += id;
            chmax(ans, anstmp);
        }
    }
    cout << ans << endl;
    return 0;
}

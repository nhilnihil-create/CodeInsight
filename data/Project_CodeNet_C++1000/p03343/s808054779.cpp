#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int (i)=0;(i)<(n);++(i))
#define FOR(i,a,b) for(int (i)=(a);(i)<(b);++(i))
#define EACH(e,v) for(auto& e:v)
#define ALL(v) (v).begin(),(v).end()
#define SORT(v) sort(ALL(v))
#define RSORT(v) sort((v).rbegin(),(v).rend())
#define PERM(v) SORT(v);for(bool c##p=1;c##p;c##p=next_permutation(ALL(v)))
#define UNIQUE(v) SORT(v);(v).erase(unique(ALL(v)),(v).end())
template<typename A,typename B> inline bool chmax(A &a,const B &b){if(a<b){a=b;return 1;}return 0;}
template<typename A,typename B> inline bool chmin(A &a,const B &b){if(a>b){a=b;return 1;}return 0;}

const int MOD = (int)1e9 + 7;
const int INF = 1 << 30;
const ll INFF = 1LL << 62;

int N, K, Q;
vector<int> A;

signed main() {

    cin >> N >> K >> Q;

    A.resize(N);
    REP(i, N) cin >> A[i];

    int res = INT_MAX;

    // A[i]をXにする
    REP(i, N) {
        vector<int> cand, v;
        REP(j, N) {
            if (A[j] < A[i]) {
                int sz = v.size();
                if (sz != 0) {
                    SORT(v);
                    REP(k, max(0, sz - K + 1)) {
                        cand.emplace_back(v[k]);
                    }
                    vector<int>().swap(v);
                }
            } else {
                v.emplace_back(A[j]);
            }
        }
        int sz = v.size();
        if (sz != 0) {
            SORT(v);
            REP(k, max(0, sz - K + 1)) {
                cand.emplace_back(v[k]);
            }
            vector<int>().swap(v);
        }
        SORT(cand);
        if ((int)cand.size() < Q) continue;
        res = min(res, cand[Q - 1] - A[i]);
    }

    cout << res << endl;

}
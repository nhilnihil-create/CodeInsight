#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)

typedef long long Int;
typedef pair<Int,Int> P;

Int power(Int a, Int n) {
    Int res = 1;
    while (n > 0) {
        if (n & 1) res = res * a;
        a = a * a;
        n >>= 1;
    }
    return res;
}


int main() {
    Int N, M;
    cin >> N;
    M = power(2,N);

    vector<Int> A(M);
    rep(i,M) cin >> A[i];

    vector<P> m1(M), m2(M);
    rep(i,M) {
        m1[i] = make_pair(A[i],i);
        m2[i] = make_pair(0,-1);
    }

    rep(i,N) rep(k,M) {
        if (!(k & (1<<i))) {
            Int j = (k | (1<<i));
            if (m1[k].first > m1[j].first) {
                m2[j] = m1[j];
                m1[j] = m1[k];
                if (m2[k].first > m2[j].first) {
                    m2[j] = m2[k];
                }
            }
            else if (m1[k].first == m1[j].first) {
                if (m1[k].second == m1[j].second) {
                    if (m2[k].first > m2[j].first) {
                        m2[j] = m2[k];
                    }
                }
                else {
                    m2[j] = m1[k];
                }
            }
            else if (m1[k].first > m2[j].first) {
                m2[j] = m1[k];
            }
        }
    }
    
    

    Int ans = 0;
    rep1(i,M-1) {
        ans = max(ans, m1[i].first + m2[i].first);
        cout << ans << endl;
    }



    return 0;
}

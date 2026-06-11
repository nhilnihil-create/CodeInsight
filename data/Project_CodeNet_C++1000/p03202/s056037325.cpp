#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) cerr << #x << " :: " << x << endl
#define _ << " " <<
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for (int i=(a);i>=(b);--i)
using ii=pair<int,int>;

const int mxN = 2e5+5;

int N, A[mxN];
ii stk[mxN]; int tp;

inline bool check(int C) {
    if (C == 0) return 0;
    stk[0] = ii(0,0); tp = 1;
    A[0] = 0;
    FOR(i,1,N){
        if (A[i] > A[i-1]) {
            stk[tp++] = ii(A[i],0);
        } else {
            while (tp > 1 && stk[tp-2].first >= A[i]) --tp;
            stk[tp-1].first = A[i];
            RFOR(j,tp-1,0){
                if (j == 0) return 0;
                if (++stk[j].second == C) {
                    stk[j].second = 0;
                } else {
                    if (stk[j-1].first+1 < stk[j].first) {
                        RFOR(k,tp-1,j) stk[k+1] = stk[k];
                        ++tp;
                        stk[j] = ii(stk[j+1].first-1,stk[j+1].second-1);
                    }
                    break;
                }
            }
        }
        //cout << i << " :: ";
        //FOR(j,0,tp-1) cout << stk[j].first << ", " << stk[j].second << " | ";
        //cout << endl;
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    FOR(i,1,N){
        cin >> A[i];
    }

    int lo = 0, hi = N;
    while (hi-lo > 1) {
        int mid = (lo+hi)/2;
        if (check(mid)) hi = mid;
        else lo = mid;
    }
    cout << hi << '\n';
}


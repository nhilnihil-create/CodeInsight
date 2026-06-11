#include <bits/stdc++.h>

#ifdef DEBUG
#define PRINT(x)\
    cout<<"func "<<__func__<<": line "<<__LINE__<<": "<<#x<<" = "<<(x)<<endl;
#define PRINTA(a,first,last)\
    cout<<"func "<<__func__<<": line "<<__LINE__<<": "<<#a<<"["<<(first)<<", "<<(last)<<")"<<endl;\
    for (int i=(first);i<(last);++i){cout<<#a<<"["<<i<<"] = "<<(a)[i]<<endl;}
#else
#define PRINT(x)
#define PRINTA(a,first,last)
#endif

#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define REP(i,n) for (int i=0;i<(n);i++)
#define pb push_back

using namespace std;

typedef pair<int, int> pii;

template <class T, class U> void amin(T& x, U y) {if (x > y) x = y;}

int main(void)
{
    const int N_MAX = 2000;
    int N, K, Q;
    int A[N_MAX];
    int result = INT_MAX;
    cin >> N >> K >> Q;
    vector<pii> v;
    REP(i, N) {
        cin >> A[i];
        v.pb(pii(A[i], i));
    }
    sort(v.begin(), v.end());
    REP(i, N) {
        PRINT(i);
        vector<int> w;
        REP(j, i) {
            w.pb(v[j].second);
        }
        w.pb(-1);
        w.pb(N);
        sort(w.begin(), w.end());
        PRINTA(w, 0, w.size());
        vector<int> z;
        REP(j, w.size() - 1) {
            int first = w[j] + 1;
            int last = w[j + 1];
            int L = last - first;
            vector<int> s;
            FOR(k, first, last) {
                s.pb(A[k]);
            }
            sort(s.begin(), s.end());
            REP(k, max(0, L - K + 1)) {
                z.pb(s[k]);
            }
        }
        if (z.size() >= Q) {
            sort(z.begin(), z.end());
            amin(result, z[Q - 1] - z[0]);
        }
    }
    cout << result << endl;
    return 0;
}
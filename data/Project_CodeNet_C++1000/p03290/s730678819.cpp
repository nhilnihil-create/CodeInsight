#include <bits/stdc++.h>

using namespace std;

// template copied from others
namespace __output {
    template<class T1, class T2> void pr(const pair<T1,T2>& x);
    template<class T, size_t SZ> void pr(const array<T,SZ>& x);
    template<class T> void pr(const vector<T>& x);
    template<class T> void pr(const set<T>& x);
    template<class T1, class T2> void pr(const map<T1,T2>& x);
 
    template<class T> void pr(const T& x) { cout << x; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) {
        pr(first); pr(rest...);
    }
 
    template<class T1, class T2> void pr(const pair<T1,T2>& x) {
        pr("{",x.first,", ",x.second,"}");
    }
    template<class T, bool pretty = true> void prContain(const T& x) {
        if (pretty) pr("{");
        bool fst = 1; for (const auto& a: x) pr(!fst?pretty?", ":" ":"",a), fst = 0;
        if (pretty) pr("}");
    }
    template<class T> void pc(const T& x) { prContain<T, false>(x); pr("\n"); }
    template<class T, size_t SZ> void pr(const array<T,SZ>& x) { prContain(x); }
    template<class T> void pr(const vector<T>& x) { prContain(x); }
    template<class T> void pr(const set<T>& x) { prContain(x); }
    template<class T1, class T2> void pr(const map<T1,T2>& x) { prContain(x); }
 
    void ps() { pr("\n"); }
    template<class Arg> void ps(const Arg& first) {
        pr(first); ps();
    }
    template<class Arg, class... Args> void ps(const Arg& first, const Args&... rest) {
        pr(first," "); ps(rest...);
    }
}
using namespace __output;

#ifdef DBG
    #define TRACE(x) x
#else
    #define TRACE(x)
#endif

#define p(x) TRACE(pr(x); cout << endl;)
#define __pn(x) pr(#x, " = ")
#define pd(...) TRACE(__pn((__VA_ARGS__)); ps(__VA_ARGS__); cout << flush;)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int D, G;
    cin >> D >> G;

    int best = 0;
    vector<int> c(D);
    vector<int> z(D);
    for (int i = 0; i < D; ++i) {
        cin >> z[i] >> c[i];
        best += z[i];
    }

    for (int i = 0; i < (1 << D); ++i) {
        int get = 0;
        int use = 0;
        for (int j = 0; j < D; ++j) {
            if ((1 << j) & i) {
                get += z[j] * 100 * (j + 1) + c[j];
                use += z[j];
            }
        }

        for (int j = D - 1; j >= 0; --j) {
            if (get < G && ((1 << j) & i) == 0) {
                int take = min(z[j], ((G - get + 100 * (j + 1) - 1) / (100 * (j + 1))));
                use += take;
                get += take * 100 * (j + 1);
            }
        }

        best = min(best, use);
    }

    cout << best << "\n";

    return 0;
}

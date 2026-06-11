#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

#define CPP_STR(x) CPP_STR_I(x)
#define CPP_CAT(x,y) CPP_CAT_I(x,y)
#define CPP_STR_I(args...) #args
#define CPP_CAT_I(x,y) x ## y

#define FOR(i, start, end) for(ll i = (start), CPP_CAT(i,xxxx_end)=(end); i < CPP_CAT(i,xxxx_end); ++i)
#define REP(i, n) FOR(i, 0, n)

int main(void) {
    int N;
    cin >> N;
    vector<int> C(N);
    vector<int> S(N);
    vector<int> F(N);

    FOR (i, 1, N) {
        cin >> C[i] >> S[i] >> F[i];
    }

    FOR (i, 1, N) {
        int t = 0;
        FOR (j, i, N) {
            t = max(t, S[j]);
            if (t % F[j] != 0) {
                t = (t / F[j] + 1) * F[j];
            }
            t += C[j];
        }
        cout << t << endl;
    }
    cout << 0 << endl;

    return 0;
}
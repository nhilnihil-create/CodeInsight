#include "bits/stdc++.h"
using namespace std;
#define Rep(i, n) for (int i = 0; i < (int)(n); i++)
#define BitRep(i, n) for (int i = 0; i < (int)(1 << n); i++)
#define All(vec) vec.begin(), vec.end()
#define Sum(vec) accumulate(vec.begin(), vec.end(), 0)
#define Sort(vec) sort(vec.begin(), vec.end())
#define Reverse(vec) reverse(vec.begin(), vec.end())
#define Next_permutation(vec) next_permutation(vec.begin(), vec.end())
#define PI acos(-1)
typedef long long ll;

int gcd(int x, int y) {
    int r = y % x;
    if (r == 0) return x;
    else return gcd(r, x);
}

int main() {
    int N, X;
    cin >> N >> X;
    vector<int> ans(N);
    Rep(i, N) {
        int x;
        cin >> x;
        ans[i] = abs(X - x);
        if (i) ans[i] = gcd(ans[i - 1], ans[i]);
    }
    cout << ans[N - 1] << endl;
    return 0;
}
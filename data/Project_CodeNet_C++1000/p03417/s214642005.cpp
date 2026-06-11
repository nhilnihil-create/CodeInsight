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

int main() {
    ll N, M;
    cin >> N >> M;
    if (N == 1 && M == 1)cout << 1 << endl;
    else if (N > 2 && M > 2) cout << (N - 2) * (M - 2) << endl;
    else if (N == 2 || M == 2) cout << 0 << endl;
    else cout << max(N, M) - 2 << endl;
    return 0;
}
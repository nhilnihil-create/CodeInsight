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
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    Rep(i, N) cin >> A[i];
    cout << (N + K - 3) / (K - 1) << endl;
    return 0;
}
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
    vector<int> cnt(N + 1);
    Rep(i, N) {
        int a;
        cin >> a;
        cnt[a]++;
    }
    int kind = 0;
    Rep(i, N + 1) {
        if (cnt[i]) kind++;
        else cnt[i] = 10000000;
    }
    Sort(cnt);
    int ans = 0;
    Rep(i, kind - K) {
        ans += cnt[i];
    }
    cout << ans << endl;
    return 0;
}
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define Rep(i, n) for (int i = 0; i < (int)(n); i++)
#define BitRep(i, n) for (int i = 0; i < (int)(1 << n); i++)
#define All(vec) vec.begin(), vec.end()
#define Sum(vec) accumulate(vec.begin(), vec.end(), 0)
#define Sort(vec) sort(vec.begin(), vec.end())
#define Reverse(vec) reverse(vec.begin(), vec.end())
#define Next_permutation(vec) next_permutation(vec.begin(), vec.end())
#define PI acos(-1)

int main() {
    int N;
    string S;
    cin >> N >> S;
    int cnt = 0;
    for (int i = 1; i < S.size(); i++) {
        if (S[i] == 'E') cnt++;
    }
    int ans = cnt;
    for (int i = 1; i < S.size(); i++) {
        if (S[i - 1] == 'W') cnt++;
        if (S[i] == 'E') cnt--;
        ans = min(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}
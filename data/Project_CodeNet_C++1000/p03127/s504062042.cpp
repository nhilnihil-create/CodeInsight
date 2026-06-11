#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define Rep(i, n) for (int i = 0; i < (int)(n); i++)
#define BitRep(i, n) for (int i = 0; i < (int)(1 << n); i++)
#define All(vec) vec.begin(), vec.end()
#define Sum(vec) accumulate(vec.begin(), vec.end(), 0)
#define Sort(vec) sort(vec.begin(), vec.end())
#define Reverse(vec) reverse(vec.begin(), vec.end())
#define Count(vec, x) count(vec.begin(), vec.end(), x)
#define Next_permutation(vec) next_permutation(vec.begin(), vec.end())
#define PI acos(-1)

int gcd(int x, int y) {
    if (x == 0) return y;
    else return gcd(y % x, x);
}

int main() {
    int N;
    cin >> N;
    int ans;
    cin >> ans;
    Rep(i, N - 1) {
        int a;
        cin >> a;
        ans = gcd(ans, a);
    }
    cout << ans << endl;
    return 0;
}
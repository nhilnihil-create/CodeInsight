#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

#define lpsbd(i, s, b, d) for(size_t i = (s); i < (b); i+=(d))
#define lpsb(i, s, b) for(size_t i = (s); i < (b); i++)
#define lpn(i, n) for(size_t i = 0; i < (n); i++)
#define fa(i, x) for(auto &i: x)
#define vcd(t, n, d) vector<t>(n, d)
#define vc(t, n) vector<t>(n)
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;

const ll MOD = 1000000007;

int main(void)
{
    int K;
    cin >> K;
    auto A = vc(int, K);
    lpn(i, K) cin >> A[K - i - 1];
    ll omx = 2, omn = 2;
    ll mx, mn;
    lpn(i, K)
    {
        mx = (omx) / A[i] * A[i] + A[i] - 1;
        mn = (omn + A[i] - 1) / A[i] * A[i];
        if (mn > mx)
        {
            cout << -1 << endl;
            return 0;
        }
        omx = mx;
        omn = mn;
    }
    cout << mn << " " << mx << endl;
    return 0;
}
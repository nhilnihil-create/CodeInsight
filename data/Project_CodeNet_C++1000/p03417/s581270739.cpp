#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>
#include <bitset>
#include <cmath>
#include <stack>
#include <iomanip>
#include <map>
#include <math.h>
typedef long long ll;
using namespace std;
const int MOD = 1000000007;

ll GCD(ll a, ll b) { return b ? GCD(b, a%b) : a; }

int main()
{
    ll N,M;
    cin >> N >> M;
    if(N == 1 || M == 1)
    {
        if(N > 1 || M > 1)
        {
            cout << max(N,M) - 2 << endl;
            return(0);
        }
        else if (N == 1 && M == 1)
        {
            cout << 1 << endl;
            return 0;
        }
    }
    cout << N * M - (2 * N + 2 * M - 4) << endl;
}
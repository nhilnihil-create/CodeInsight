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
    int N,K;
    cin >> N >> K;
    int x[N];
    for(int i = 0; i < N; i++) cin >> x[i];
    ll ans = 1000000000000;
    for(int i = 0; i < N - K + 1; i++)
    {
        ll left = x[i];
        ll right = x[i + K - 1];
        ans = min(ans, min(abs(left), abs(right)) + right - left);
    }
    cout << ans << endl;
}
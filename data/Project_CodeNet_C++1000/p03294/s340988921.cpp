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
    int N;
    cin >> N;
    ll a[N];
    for(int i = 0; i < N; i++) cin >> a[i];

    ll ans = 0;
    for(int i = 0; i < N; i++)
    {
        ans += a[i] - 1;
    }
    cout << ans << endl;
}
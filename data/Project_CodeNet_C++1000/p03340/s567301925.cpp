#include <iostream>
using namespace std;

typedef long long ll;

const int maxn = 2e5 + 5;

int main(int argc, const char * argv[])
{
    ll n, a[maxn], sum[maxn] = {0}, x[maxn] = {0}, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        sum[i] = sum[i-1] + a[i];
        x[i] = x[i-1] ^ a[i];
    }

    for(int l = 1, r = 1; r <= n; r++) {
        while (sum[r] - sum[l-1] != (x[r] ^ x[l-1])) l++;
        ans += r - l + 1;
    }

    cout << ans << endl;
    return 0;
}
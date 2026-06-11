#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define MAX(a, b) ((a) < (b) ? (b) : (a))

const long long INF = 1LL << 60;
typedef long long ll;
const long long MOD = 1000000000 + 7;

int main()
{
    ll n, a, b, c, d, e;
    cin >> n >> a >> b >> c >> d >> e;
    ll min_transe;
    min_transe = MIN(a, b);
    min_transe = MIN(min_transe, c);
    min_transe = MIN(min_transe, d);
    min_transe = MIN(min_transe, e);
    cout << 4 + (n + (min_transe - 1)) / min_transe << endl;
    return 0;
}
#include <iostream>
#include <iomanip>
typedef long long ll;
using namespace std;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
#define repi(i, n, init) for (ll i = init; i < (n); i++)

int main()
{
    int n, k, ans = 1;
    cin >> n >> k;
    repi(i,n,0){
        ans = min(ans * 2,ans + k);
    }
    cout << ans << endl;
    return 0;
}
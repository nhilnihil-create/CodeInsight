#include <iostream>
#include <iomanip>
#include <vector>
typedef long long ll;
using namespace std;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
#define repi(i, n, init) for (ll i = init; i < (n); i++)

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> a(2, vector<int>(n, 0));
    repi(i, 2, 0)
    {
        repi(j, n, 0)
        {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    repi(i,n,0){
        int s = 0;
        repi(j,i + 1,0){
            s += a[0][j];
        }
        repi(j,n,i){
            s += a[1][j];
        }
        ans = max(ans,s);
    }
    cout << ans << endl;

    return 0;
}
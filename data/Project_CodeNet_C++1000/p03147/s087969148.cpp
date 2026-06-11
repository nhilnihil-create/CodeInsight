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
    vector<int> h(n, 0);
    repi(i, n, 0) cin >> h[i];
    int ans = 0,prev = -1;
    bool ok = false;
    while(ans != prev){
        prev = ans;
        repi(i,n,0){
            if(h[i]){
                h[i]--;
                ok = true;
            }else if(ok){
                ans++;
                ok = false;
            }
        }
        if(ok){
            ok = false;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
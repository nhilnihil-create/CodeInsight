#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

ll N;
ll ans = 0;
void saiki(ll cur, int use)
{
    if (cur > N)
        return;
    if (use == 0b111)
        ans++;

    saiki(cur * 10 + 7, use | 0b001);
    saiki(cur * 10 + 5, use | 0b010);
    saiki(cur * 10 + 3, use | 0b100);
}
int main()
{
    cin >> N;
    saiki(0, 0b000);
    cout << ans << endl;
}
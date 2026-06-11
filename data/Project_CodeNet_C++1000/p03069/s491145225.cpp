#include <iostream>
#include <iomanip>
#include <string>
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
    string s;
    cin >> s;
    vector<int> whsum(n + 1, 0), blsum(n + 1, 0);
    repi(i, n, 0)
    {
        whsum[i + 1] = whsum[i] + (s[i] == '.' ? 1 : 0);
        blsum[i + 1] = blsum[i] + (s[i] == '#' ? 1 : 0);
    }
    int ans = INF;
    repi(left, n + 1, 0)
    {
        int tmp = 0;
        tmp += blsum[left];
        tmp += whsum[n] - whsum[left];
        ans = min(tmp, ans);
    }
    cout << ans << endl;
    return 0;
}
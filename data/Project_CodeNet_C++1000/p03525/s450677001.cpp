#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

#define lpsbd(i, s, b, d) for(size_t i = (s); i < (b); i+=(d))
#define lpsb(i, s, b) for(size_t i = (s); i < (b); i++)
#define lpn(i, n) for(size_t i = 0; i < (n); i++)
#define fa(i, x) for(auto &i: x)
#define vcd(t, n, d) vector<t>(n, d)
#define vc(t, n) vector<t>(n)
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;

const ll MOD = 1000000007;

int main(void)
{
    int N;
    cin >> N;
    int D;
    int dn[13] = {0};
    dn[0] = 1;
    lpn(i, N)
    {
        cin >> D;
        dn[D]++;
    }
    if (dn[0] >= 2 || dn[12] >= 2)
    {
        cout << 0 << endl;
        return 0;
    }
    vector<int> opt;
    opt.push_back(0);
    opt.push_back(24);
    if (dn[12]) opt.push_back(12);
    bool lr = true;
    lpsb(i, 1, 12)
    {
        switch (dn[i])
        {
        case 1:
            opt.push_back((lr ? i : 24 - i));
            lr = !lr;
            break;

        case 2:
            opt.push_back(i);
            opt.push_back(24 - i);
        case 0:
            break;

        default:
            cout << 0 << endl;
            return 0;
        }
    }
    int ans = 24;
    sort(all(opt));
    for (int i = opt.size()-1; i >= 1; i--) ans = min(ans, opt[i] - opt[i-1]);
    cout << ans << endl;

    return 0;
}
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define pbds tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define mod 1000000007
#define deb(x) cerr << "\n" \
                    << #x << "=" << x << "\n";
#define deb2(x, y) cerr << "\n"                   \
                        << #x << "=" << x << "\n" \
                        << #y << "=" << y << "\n";
#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    w(tt)
    {
        int a, b;
        cin >> a >> b;

        if (b > a)
            swap(a, b);

        if (a == b || a + 1 == b)
        {
            cout << 2 * (a - 1) << "\n";
        }
        else
        {
            int sq = sqrt(a * b);
            if (sq * sq == a * b)
                sq--;

            if (sq * (sq + 1) >= a * b)
            {
                cout << 2 * (sq - 1) << "\n";
            }
            else
            {
                cout << 2 * (sq - 1) + 1 << "\n";
            }
        }
    }

    return 0;
}
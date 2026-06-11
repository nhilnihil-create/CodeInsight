/*---------------Go Code GO---------------*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using Order_Set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//(order) Set.order_of_key(); (pointer) Set.find_by_order();

#define PI acos(-1.0)
#define O_O                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define precision(a) fixed << setprecision(a)
#define endl '\n'
#define Flush cout << flush
#define LLMX 0x3fffffffffffffff

long long N;

int main()
{
    O_O;

    long long N;
    cin >> N;
    long long sum[N], val[N];
    for (int i = 0; i < N; i++)
    {
        cin >> val[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> sum[i];
    }
    long long ans = 0;
    for (int i = 0; i < (1LL << N); i++)
    {
        long long x = 0;
        long long y = 0;
        for (int j = 0; j < N; j++)
        {
            if (i & (1LL << j))
            {
                y += sum[j];
                x += val[j];
            }
        }
        ans = max(ans, (x - y));
    }
    cout << ans << endl;

    return 0;
}
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

    string S;
    cin >> S;
    string mask1;
    string mask2;

    for (int i = 0; i < S.size(); i++)
    {
        if (i % 2 == 0)
            mask1.push_back('0'), mask2.push_back('1');
        else
            mask1.push_back('1'), mask2.push_back('0');
    }
    long long ans = S.size(), x = 0, y = 0;
    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] != mask1[i])
            x++;
        if (S[i] != mask2[i])
            y++;
    }
    cout << min(x, y) << endl;

    return 0;
}
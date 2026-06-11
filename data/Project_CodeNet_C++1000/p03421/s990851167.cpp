// Math = ♥️

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

/*-------------------------------------------------------------------------------------------------------------------------*/
#define ll long long                  // Short form for long long
#define ld long double                // Short form for long double
typedef pair<ll, ll> ii;              // Pair of long long
typedef vector<ll> vi;                // Vector of long long
typedef vector<vi> vvi;               // Vector of vector of long long
typedef vector<ii> vii;               // Vector of pairs
typedef vector<vii> vvii;             // Vector of vector of pairs
#define pq priority_queue             // Max heap (To convert to min heap, use negative sign before every value)
#define ff first                      // For pairs
#define ss second                     // For pairs
#define pb push_back                  // Pushback to vector
#define mp make_pair                  // Makes pairs to be stored as pair
#define all(c) (c).begin(), (c).end() // Mainly used by me in sorting
// ordered_set adds two new functions to set - (set).find_by_order([kth element based on zero indexing]) and order_of_key()
// order_of_key returns number of elements less that parameter. If element exists, that order is its index
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
/*-------------------------------------------------------------------------------------------------------------------------*/

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, a, b;
    cin >> n >> a >> b;

    if (n < (a + b - 1) || n > (a * b))
    {
        cout << "-1\n";
        return 0;
    }

    for (int i = b; i >= 1; i--)
        cout << i << " ";

    n -= b;
    a--;

    if (a == 0)
        return 0;

    ll each = n / a;
    ll extra = n % a;

    ll curr = b;

    for (int i = 0; i < extra; i++)
    {
        for (int j = curr + each + 1; j > curr; j--)
            cout << j << " ";
        curr += each + 1;
    }

    a -= extra;
    for (int i = 0; i < a; i++)
    {
        for (int j = curr + each; j > curr; j--)
            cout << j << " ";
        curr += each;
    }
}

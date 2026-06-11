#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <fstream>
#define ni(n) scanf("%d", &n)
#define nl(n) scanf("%lld", &n)
#define nai(a,n) for (int i = 0; i < (n); i++) ni((a)[i])
#define nal(a,n) for (int i = 0; i < (n); i++) nl((a)[i])
#define case(t) printf("Case #%d: ", (t))
#define pii pair<int, int>
#define vii vector<pii>
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define f first
#define s second
typedef long long ll;
const double pi = acos(-1);
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const int MAXN = 1e5 + 5;
const double eps = 1e-9;
using namespace std;

int main()
{
    int q;
    ni(q);
    for (int i = 0; i < q; i++)
    {
        ll a, b;
        nl(a), nl(b);
        ll ans = 0;
        if (a > b)
            swap(a, b);
        if (a == b)
            ans = 2 * a - 2;
        else if (a + 1 == b)
            ans = 2 * a - 2;
        else
        {
            ll c = floor(sqrt(a * b));
            if (c * c == a * b)
                c--;
            if (c * (c + 1) >= a * b)
                ans = 2 * c - 2;
            else if (c * (c + 1) < a * b)
                ans = 2 * c - 1;
        }
        printf("%lld\n", ans);
    }
    return 0;
}

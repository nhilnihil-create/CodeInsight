#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define trav(a, x) for (auto &a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int main()
{
    // freopen("B.01.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, alice = 0, bob = 0;
    cin >> n;
    vi a(n);
    rep(i, 0, n)
    {
        cin >> a[i];
    }
    sort(all(a));
    reverse(all(a));
    // trav(it, a){
    //     printf("%d ",it);
    // }
    rep(i, 0, n)
    {
        if (i % 2 == 0)
        {
            alice += a[i];
        }
        else
        {
            bob += a[i];
        }
    }
     cout << alice - bob << endl;
    return 0;
}
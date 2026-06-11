#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, n) for (int i = 1; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;

    ld prob = n >= k ? (ld)(n - k + 1) / n : 0;
    int prev = k;
    ll pcoinInv = 1;
    while (k > 0) {
        k = (k + 1) /2;
        if (prev == k) {
            break;
        }
        pcoinInv *= 2;
        if (n >= k) {
            ld p1 = (ld)(min(prev, n+1) - k) / n;
            prob += p1 / pcoinInv;
//            cout << n << "|" <<  k << " " <<  p1 << "/" << pcoin << endl;
        }
        prev = k;
    }

    printf("%.12Lf\n", prob);

    return 0;
}
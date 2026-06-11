#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
#define eps 1e-9

typedef long long ll;

using namespace std;

const ll inf = 1e18;
const ll mod = 1e9+7;
const int N = 1e5+5;
int a[N];

int main()

{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, b, c, d;

    cin >> n >> b >> c >> d;

    a[n]++, a[b]++, a[c]++, a[d]++;

    if (a[1] && a[9] && a[7] && a[4]) cout << "YES";
    else cout << "NO";

    return 0;
}

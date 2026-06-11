#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
using namespace std;
using ll = unsigned long long;
using p = pair<int, int>;

int main()
{
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i, 0, N)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end(), greater<int>());

    int alice = 0;
    int bob = 0;

    rep(i, 0, N)
    {
        if (i % 2 == 0)
        {
            alice += a[i];
            continue;
        }
        bob += a[i];
    }

    cout << alice - bob << endl;

    return 0;
}

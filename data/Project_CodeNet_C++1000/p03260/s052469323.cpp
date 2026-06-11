#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int f(int n)
{
    return ((n & 1) ? 3 * n + 1 : n / 2);
}

int main()
{
    int a,b;
    cin >> a >> b;

    cout <<((a&1 && b&1)?"Yes":"No") << '\n';
    return 0;
}

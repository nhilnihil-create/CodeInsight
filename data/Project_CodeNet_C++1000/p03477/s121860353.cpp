#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    cout << ((a + b > c + d) ? "Left" : (a + b == c + d) ? "Balanced" : "Right") << '\n';

    return 0;
}

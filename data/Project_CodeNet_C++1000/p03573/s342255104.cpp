#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

const int MOD = 1e9 + 7;

int main()
{
    int a, b,c;
    cin >> a >> b>>c;

    cout << ((a==b)?c:(b==c)?a:b) << endl;
    return 0;
}

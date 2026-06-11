#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define all2(a, b) (a).begin(), (a).begin() + (b)
#define debug(vari) cerr << #vari << " = " << (vari) << endl;

int main()
{
    int a, b;
    cin >> a >> b;

    if (a % 2 == 0 || b % 2 == 0)
    {
        cout << "Even" << endl;
        return (0);
    }
    cout << "Odd" << endl;
    return (0);
}

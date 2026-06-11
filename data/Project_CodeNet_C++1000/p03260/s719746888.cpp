#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int a, b;
    cin >> a >> b;
    for (int c = 1; c < 4; c++)
    {
        int n = a * b * c;
        if (n % 2 == 1)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
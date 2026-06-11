#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int, int>;

int main() {
    int A, B;
    cin >> A >> B;
    if (A <= 5)
    {
        cout << 0 << endl;
    }
    else if (A >= 13)
    {
        cout << B << endl;
    }
    else
    {
        cout << B / 2 << endl;
    }
    return 0;
}
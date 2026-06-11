#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll A, B, C;
    cin >> A >> B >> C;
    cout << B + min(A + B + 1, C) << endl;
    return 0;
}

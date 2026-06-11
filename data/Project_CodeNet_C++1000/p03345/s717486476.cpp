#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll A, B, C, K;
    ll a, b, c;
    cin >> A >> B >> C >> K;
    if (abs(A - B) > 1000000000000000000)
    {
        cout << "unfair " << endl;
        return 0;
    }
    if (K % 2 != 0)
    {
        cout << B - A << endl;
    }
    else
    {
        cout << A - B << endl;
    }
}

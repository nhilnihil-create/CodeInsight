#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int(i) = 0; (i) < (n); (i)++)

int main()
{
    int A, B, C;

    cin >> A >> B >> C;
    if (A > B)
    {
        if (C < A && C > B)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    else
    {
        if (C > A && C < B)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
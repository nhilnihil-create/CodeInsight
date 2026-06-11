#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

using ll = long long;
using P = pair<int, int>;

int main()
{
    int A, B, K;
    cin >> A >> B >> K;
    for (int i = 100; i > 0; i--)
    {
        if (A % i == 0 && B % i == 0)
        {
            K--;
            if (K == 0)
                cout << i << endl;
        }
    }
    return 0;
}
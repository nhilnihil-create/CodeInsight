#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int(i) = 0; (i) < (n); (i)++)

int main()
{
    int N, K;
    cin >> N >> K;

    if (K * 2 - 1 <= N)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}
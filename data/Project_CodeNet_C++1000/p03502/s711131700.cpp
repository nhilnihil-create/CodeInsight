#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main()
{
    int N;
    cin >> N;
    int f = 0;
    int n = N;
    rep(i, 10)
    {
        f += N % 10;
        N /= 10;
    }
    if (n % f == 0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
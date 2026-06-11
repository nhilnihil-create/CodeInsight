#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define MAX(a, b) ((a) < (b) ? (b) : (a))

const long long INF = 1LL << 60;
typedef unsigned long long ll;
const long long MOD = 1000000000 + 7;

int main()
{
    int n, k;
    cin >> n >> k;
    int out = 1;
    rep(i, n)
    {
        if (out < k)
        {
            out *= 2;
        }
        else
        {
            out += k;
        }
    }
    cout << out << endl;
    return 0;
}
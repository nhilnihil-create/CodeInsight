#include <bits/stdc++.h>
using namespace std;

#define    ll     long long int

const int N = 100005;
int ara[N];

int main( )
{
    int n, i, j, k, s = 0;
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> ara[i];
        s += abs(ara[i] - ara[i - 1]);
    }
    s += abs(ara[i - 1]);
    ara[i] = 0;
    for (i = 1; i <= n; i++) {
        cout << (s - abs(ara[i] - ara[i - 1]) - abs(ara[i + 1] - ara[i]) + abs(ara[i + 1] - ara[i - 1])) << '\n';
    }
    return 0;
}

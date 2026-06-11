#include <bits/stdc++.h>
using namespace std;

long long int K;

int sum(long long n)
{
    int res = 0;
    while (n > 0)
    {
        res += n % 10;
        n /= 10;
    }
    return res;
}

int main()
{
    cin >> K;
    long long int now = 0;
    long long int diff = 1;
    while (K > 0)
    {
        if ((now + diff) * sum(now + diff * 10) > (now + diff * 10) * sum(now+diff)) diff *= 10;
        now += diff;
        cout << now << endl;
        K--;
    }
    // int N = 1000000;
    // vector<double> a(N + 1);
    // for (int i = 1; i <= N; i++) a[i] = (double)i / sum(i);

    // vector<double> mins(N + 1);
    // mins[N] = a[N];
    // for (int i = N-1; i > 0; i--) mins[i] = min(mins[i+1], a[i]);
    // for (int i = 1; i <= N; i++) if (a[i] == mins[i]) cout << i << endl;
    return 0;
}

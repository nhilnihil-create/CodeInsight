#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

#define NMAX 200001

int v[NMAX], cost[NMAX];
__int128 s[NMAX];

__int128 solve(int k, int n) {
    __int128 sum = 0;
    int i = max(n - k + 1, 1);
    int j = n;
    int cnt = 1;
    while (i <= j && i >= 1 && j >= 1) {
        sum = sum + (__int128) cost[cnt] * (s[j] - s[i - 1]);
        j = i - 1;
        i = max(1, j - k + 1);
        cnt++;
    }
    return sum;
}

string to_string128(__int128 x) {
    string str;
    if (x == 0) {
        return "0";
    }
    while (x > 0) {
        str.push_back(x % 10 + '0');
        x = x / 10;
    }
    reverse(str.begin(), str.end());
    return str;
}

int main()
{
    int n, x;
    ios::sync_with_stdio(false);
    // ifstream cin("code.in");
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + (__int128) v[i];
    }
    cost[1] = 5;
    for (int i = 2; i <= n; i++) {
        cost[i] = 2 * i + 1;
    }

    __int128 sol = ((__int128)5) * s[n] + (__int128) n * x;
    for (int i = 1; i < n; i++) {
        __int128 aux = solve(i, n) + (__int128) i * x;
        sol = min(sol, aux);
    }

    cout << to_string128(sol + (__int128) n * x);

    return 0;
}

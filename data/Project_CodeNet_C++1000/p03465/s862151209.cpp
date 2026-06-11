#include <bits/stdc++.h>

using namespace std;
const int N = 2006;
bitset <N*N> b = 1;

int main()
{
    int n, a, sum = 0; cin >> n;
    for (int i = 0; i < n; i++) cin >> a, sum += a, b |= b<<a;
    for (int i = (sum+1)/2; i <= sum; i++) if (b[i]) return cout << i << "\n", 0;
}

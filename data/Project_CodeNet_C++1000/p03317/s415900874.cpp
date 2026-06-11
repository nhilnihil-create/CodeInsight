#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using i64 = int64_t;

int main()
{
    int n, k;
    cin >> n >> k;

    n--;
    k--;
    cout << n / k + !!(n % k) << endl;
}

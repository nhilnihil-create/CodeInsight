#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using li = long long int;
using uli = unsigned long long int;
using namespace std;

int main() {
    fastIO;
    int n, k;
    cin >> n >> k;
    int sum = 1;
    while (n--) {
        if (sum * 2 > (sum + k))
            sum += k;
        else
            sum *= 2;
    }
    cout << sum << endl;
}
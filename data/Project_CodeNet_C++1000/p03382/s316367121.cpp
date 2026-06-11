#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define vec vector

int main(void)
{
    int n;
    cin >> n;
    vec<int> a(n), b(n, 1);
    rep(i, n) cin >> a[i];

    sort(a.begin(), a.end());
    rep(i, n) {
        int p = a[n - 1 - i];
        int lower = (int)(lower_bound(a.begin(), a.end(), p / 2) - a.begin()); 

        if (a[lower] == p / 2 || lower == 0) b[n - 1 - i] = a[lower];
        else {
            if (a[lower] + a[lower - 1] >= p) b[n - 1 - i] = a[lower - 1];
            else b[n - 1 - i] = a[lower];
        }
    }

    cout << a[n - 1] << " " << b[n - 1] << endl;

    return 0;
}

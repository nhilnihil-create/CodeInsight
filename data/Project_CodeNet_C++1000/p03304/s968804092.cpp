#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=(0);(i)<(int)(n);++(i))
using ll = long long;
using P = pair<int, int>;
using namespace std;

int main() {
    double n, m, d;
    cin >> n >> m >> d;

    if (d == 0) {
        printf("%.10f\n", (1.0/n) * (m-1));
    }
    else {
        printf("%.10f\n", 2 * (n - d) / (n * n) * (m - 1));
    }
}

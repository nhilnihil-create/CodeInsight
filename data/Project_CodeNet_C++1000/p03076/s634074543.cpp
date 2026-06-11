
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int sum;
int a[5];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < 5; ++i) {
        cin >> a[i];
    }
    sort(a, a + 5, [](int x, int y){
        if (x % 10 == 0) return true;
        if (y % 10 == 0) return false;
        return x % 10 > y % 10;
    });
    for (int i = 0; i < 4; ++i) {
        sum += a[i];
        int d = sum % 10;
        if (d != 0)
            sum += 10 - d;
    }
    sum += a[4];
    cout << sum << endl;

    return 0;
}


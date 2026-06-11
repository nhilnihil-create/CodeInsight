#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n], Max = 0, maxi = -1;
    for (int i = 0; i < n; i++)  {
        cin >> a[i];
        if (Max < a[i]) {
            Max = a[i];
            maxi = i;
        }
    }
    int mid1 = Max/2, mid2 = Max/2, r, deff = (1 << 30);
    if (Max % 2 != 0) mid2++;
    for (int i = 0; i < n; i++) {
        if (i == maxi) continue;
        int nowDeff = min(abs(mid1 - a[i]), abs(mid2 - a[i]));
        if (nowDeff < deff) {
            deff = nowDeff;
            r = a[i];
        }
    }
    cout << Max << " " << r << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int a, b; cin >> a >> b;
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for (int i=0; i<n; ++i) {
        int p; cin >> p;
        if (p <= a) cnt1++;
        else if (p >= b+1) cnt3++;
        else cnt2++;
    }
    cout << min({cnt1, cnt2, cnt3}) << endl;
}
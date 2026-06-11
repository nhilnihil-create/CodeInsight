#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    vector<int> l(n),r(n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &l[i], &r[i]);
        r[i] = -r[i];
    }
    sort(l.begin(), l.end(), greater<int>()); 
    sort(r.begin(), r.end(), greater<int>());

    long long ans = 0;
    int iter = 2; while (iter--) {
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += l[i]; ans = max(ans, sum);
            sum += r[i]; ans = max(ans, sum);
        }
        l.swap(r);
    }
    cout << 2*ans << endl;

    return 0;
}

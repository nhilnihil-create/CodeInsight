#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n], c[n] = {0};
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        if(a[i]%2 == 1) {
            c[i] = 1;
        } else {
            c[i] = 2;
        }
    }
    int ans = pow(3, n), m_ans = 1;
    for(int i = 0; i < n; ++i) m_ans *= c[i];
    cout << ans - m_ans << '\n';

    return 0;
}

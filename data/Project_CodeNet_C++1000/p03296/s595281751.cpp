#include <bits/stdc++.h>
using namespace std;
int main () {
    int N;
    cin >> N;
    vector<int> a(N);
    int k;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        if (i == 0) {
            k = 1;
        }
        else {
            if (a[i-1] == a[i]) {
                k++;
            }
            else {
                ans += k/2;
                k = 1;
            }
        }
    }
    ans += k/2;
    cout << ans << endl;
}
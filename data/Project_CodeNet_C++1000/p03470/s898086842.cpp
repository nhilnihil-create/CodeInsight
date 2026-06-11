#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

int main() {
    int N;
    cin >> N;
    vector<int> dn(N);
    for (int i = 0; i < N; i++) {
        cin >> dn[i];
    }
    sort(dn.begin(), dn.end(), greater<int>());

    int temp = dn[0];
    int ans = 1;
    for (int i = 0; i < N; i++) {
        if (temp > dn[i]) {
            ans += 1;
            temp = dn[i];
        }
    }
    cout << ans <<endl;
}
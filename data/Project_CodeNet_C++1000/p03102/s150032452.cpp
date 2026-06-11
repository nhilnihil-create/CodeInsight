#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, c, no_working = 0;
    cin >> n >> m >> c;
    int b_terms[m];
    for (int i = 0; i < m; i++) {
        cin >> b_terms[i];
    }
    for (int i = 0; i < n; i++) {
        int curr_sum = 0;
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            curr_sum += b_terms[j] * x;
        }
        if (curr_sum + c > 0) {
            no_working++;
        }
    }
    cout << no_working;
}


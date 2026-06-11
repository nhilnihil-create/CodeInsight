#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, A;
    int mi = 1000000005;
    int ma = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A;
        mi = min(mi, A);
        ma = max(ma, A);
    }

    cout << ma - mi << endl;
}
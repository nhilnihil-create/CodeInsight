#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> D(100);

    int d = 0;
    for (int i = 0; i < N; i++) {
        cin >> d;
        D.at(d-1)++;
    }

    int cnt = 0;
    for (int i = 0; i < 100; i++) {
        if (D.at(i) > 0) {
            cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}
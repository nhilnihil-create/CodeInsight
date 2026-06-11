#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, A, B;
    cin >> N >> A >> B;

    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;

        if (a <= A) {
            cnt1++;
        } else if (a <= B) {
            cnt2++;
        } else {
            cnt3++;
        }
    }

    cout << min({cnt1, cnt2, cnt3}) << endl;
    return 0;
}


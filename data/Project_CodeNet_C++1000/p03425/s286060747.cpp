#include <bits/stdc++.h>

using namespace std;

int main(void) {
    long N, ans = 0;
    long tbl[] = {0, 0, 0, 0, 0};
    cin >> N;
    for (int i = 0; i < N; i++) {
        string S; cin >> S;
        switch (S[0])
        {
            case 'M':
                tbl[0]++;
                break;
            case 'R':
                tbl[1]++;
                break;
            case 'A':
                tbl[2]++;
                break;
            case 'C':
                tbl[3]++;
                break;
            case 'H':
                tbl[4]++;
                break;
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            for (int k = j + 1; k < 5; k++) {
                ans += tbl[i] * tbl[j] * tbl[k];
            }
        }
    }

    cout << ans << endl;

    return 0;
}
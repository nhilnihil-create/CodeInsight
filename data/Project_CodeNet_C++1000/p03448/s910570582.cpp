#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C, X, cnt;
    cin >> A >> B >> C >> X;
    cnt = 0;

    for (int i_A = A; i_A >= 0; i_A--) {
        int sum_a = 500 * i_A;
        if (sum_a > X)
            continue;
        for (int i_B = B; i_B >= 0; i_B--)
        {
            int sum_b = sum_a + 100 * i_B;
            if (sum_b > X)
                continue;
            for (int i_C = C; i_C >= 0; i_C--)
            {
                int sum_c = sum_b + 50 * i_C;
                if (sum_c == X)
                    cnt++;
                else
                    continue;
            }
        }
    }
    cout << cnt << endl;
}
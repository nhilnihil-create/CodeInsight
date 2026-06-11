#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N; cin >> N;
    vector<int> C(13);
    C[0] = 1;
    for (int i = 0; i < N; i++) {
        int d; cin >> d;
        C[d]++;
    }
    if (any_of(C.begin(), C.end(), [](int c){return c>=3;}) || C[0]==2 || C[12]==2) {
        cout << 0 << endl;
        return 0;
    }
    int ans = 0;
    for (int b = 0; b < (1<<11); b++) {
        vector<int> D;
        for (int i = 1; i <= 11; i++) {
            if (C[i] == 2) {
                D.push_back(i);
                D.push_back(24-i);
            } else if (C[i] == 1) {
                if (b & (1 << (i-1))) {
                    D.push_back(24-i);
                } else {
                    D.push_back(i);
                }
            }
        }
        if (C[12] > 0) D.push_back(12);
        D.push_back(24);
        sort(D.begin(), D.end());
        vector<int> diffs(D.size());
        adjacent_difference(D.begin(), D.end(), diffs.begin());
        int mi = *min_element(diffs.begin(), diffs.end());
        ans = max(ans, mi);
    }

    cout << ans << endl;
}

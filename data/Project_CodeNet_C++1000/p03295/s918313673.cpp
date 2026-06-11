// 4/25
// 区間スケジューリング問題

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    pair<int, int> itv[100000];

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        itv[i].first = b;
        itv[i].second = a;
    }

    // for (int i = 0; i < M; i++) {
    //     printf("%d: %d ~ %d\n", i, itv[i].second, itv[i].first);
    // }

    // printf("sort!");
    sort(itv, itv + M);

    // for (int i = 0; i < M; i++) {
        // printf("%d: %d ~ %d\n", i, itv[i].second, itv[i].first);
    // }


    int ans = 0, d = 0;

    for (int i = 0; i < M; i++) {
        if (itv[i].second >= d) {
            // printf("%d: %d ~ %d\n", i, itv[i].second, itv[i].first);
            d = itv[i].first;
            ans++;
        }
    }

    cout << ans << endl;
}
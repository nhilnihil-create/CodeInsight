#include <bits/stdc++.h>

using P = std::pair<int, int>;

int main() {
    int N;
    std::cin >> N;

    int x, y;
    P reds[N];
    for (int i = 0; i < N; ++i) {
        std::cin >> x >> y;
        reds[i] = {x, y};
    }

    P blues[N];
    for (int i = 0; i < N; ++i) {
        std::cin >> x >> y;
        blues[i] = {x, y};
    }

    std::sort(blues, blues + N);

    int cnt = 0;
    std::set<int> used;
    for (int i = 0; i < N; ++i) {
        int red_y = -1;
        int index = -1;
        for (int j = 0; j < N; ++j) {
            if ((reds[j].first < blues[i].first && reds[j].second < blues[i].second) == false) {
                continue;
            }

            if (used.count(j) != 0) {
                continue;
            }

            if (red_y < reds[j].second) {
                red_y = reds[j].second;
                index = j;
            }
        }

        if (index != -1) {
            ++cnt;
            used.insert(index);
        }
    }
    
    std::cout << cnt << std::endl;

    return 0;
}

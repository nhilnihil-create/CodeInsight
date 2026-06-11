// 4/26 Greedy

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    pair<int, int> red[N], blue[N];
 
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        red[i] = make_pair(a, b);
    }

    for (int i = 0; i < N; i++) {
        int c, d;
        cin >> c >> d;
        blue[i] = make_pair(c, d);
    }

    // for (int i = 0; i < N; i++) {
    //     printf("a, b, c, d = %d, %d, %d, %d\n", red[i].first, red[i].second, blue[i].first, blue[i].second);
    // }

    sort(red, red + N);
    sort(blue, blue + N);

    bool red_have_pair[N] = {false};
    int ans = 0;

    for (int i = 0; i < N; i++) {
        int x = blue[i].first;
        int y = blue[i].second;

        int max_y = -1;
        int pair_red = -1;

        for (int j = 0; j < N; j++) {
            if (red[j].first < x && red[j].second < y && red_have_pair[j] != true) {
                // cout << "here?" << endl;
                if (max_y < red[j].second) {
                    max_y = red[j].second;
                    pair_red = j;
                    // cout << "here?2" << endl;
                }
            }
        }

        if (pair_red != -1) {
            red_have_pair[pair_red] = true;
            ans++;
        }
    }

    // for (int l = 0; l <= 4 * N; l++) {
    //     // cout << "l: " << l << endl;

    //     for (int x = 0; x <= l; x++) {
    //         int y = l - x;

    //         std::cout << "x, y = " << x << ", " << y << endl;

    //         // lがある値の時のブルーを１つずつ探す。
    //         for (int i = 0; i < N; i++) {
    //             bool find_pair = false;
    //             if (blue[i].first == x && blue[i].second == y) {
    //                 std::cout << "find blue!" << endl;

    //                 for (int j = 0; j < N; j++) {
    //                     if (red[j].first < x && red[j].second < y && have_pair[j] != true) {
    //                         have_pair[j] = true;
    //                         find_pair = true;
    //                         ans += 1;
    //                         break;
    //                     }
    //                 }
    //             }

    //             // // ペアを見つけていたら次のブルーへ。
    //             // if (find_pair) break;
    //         }
    //     }
    // }

    cout << ans << endl;
}
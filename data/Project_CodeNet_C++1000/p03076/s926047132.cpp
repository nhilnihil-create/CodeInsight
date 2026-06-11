#include<iostream>
using namespace std;

int main() {
    int time[5];
    int ans = 0;
    int last_dish;
    int last_dish_time = 0;
    int fixed_time[5];
    for (int i = 0; i < 5; i++) {
        cin >> time[i];
    }
    for (int i = 0; i < 5; i++) {
        if (time[i] % 10 == 0) {
            fixed_time[i] = time[i];
        } else {
            fixed_time[i] = 10 * (time[i] / 10 + 1);
        }
        if (last_dish_time < fixed_time[i] - time[i]) {
            last_dish_time = fixed_time[i] - time[i];
            last_dish = i;
        }
    }
    for (int i = 0; i < 5; i++) {
        if (i == last_dish) {
            ans += time[i];
        } else {
            ans += fixed_time[i];
        }
    }
    cout << ans << endl;
}

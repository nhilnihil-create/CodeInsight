
#include <iostream>
#include <iomanip>
using namespace std;

void Main() {
    // input
     int N;
     cin >> N;
     int now_t = 0, now_x = 0, now_y = 0;
     int next_t, next_x, next_y;

    
     for(int i = 0; i < N; i++) {
         cin >> next_t >> next_x >> next_y;
         int diff_t = next_t - now_t;
         int diff_x = next_x - now_x;
         int diff_y = next_y - now_y;

        diff_t -= abs(diff_x) + abs(diff_y);
        if (diff_t < 0 || diff_t % 2 == 1) {
            cout << "No" << endl;
            return;
        }

        now_t = next_t;
        now_x = next_x;
        now_y = next_y;
     }

    cout << "Yes" << endl;

    // translate


    // output

}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
